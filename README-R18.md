# asn1c-r18 — fork notes

This is a fork of [vlm/asn1c](https://github.com/vlm/asn1c) adapted to compile the
3GPP ASN.1 specifications for **RRC, NGAP and XNAP** up to ***3GPP Release 18**.

Everything in upstream asn1c works as documented in [README.md](README.md); this
file covers **only what the fork adds or changes**. Upstream is merged in through
v0.9.29 plus its post-release fixes (including CVE-2025-32893).

Portions of this fork were created using Anthropic Claude.  Model versions: Sonnet 4.6, Opus 5

---

## Added command-line options

Three options are added to `asn1c`. All use the `-f<name>` construction, matching upstream's
convention for compiler flags.

| Option | Effect |
| ------ | ------ |
| `-fcommon` | Write skeleton/support files to a shared directory named `asn1c` instead of into the `-D` output directory. Requires `-D`. |
| `-fcommon=<name>` | As above, using `<name>` for the directory. An empty `<name>` falls back to `asn1c`. |
| `-fprefix=<prefix>` | Prepend `<prefix>` to generated **output file names**, their include guards, and the **C identifiers** — so several specifications can be linked into one binary. |

`asn1c -h` will list every option the compiler accepts, including these additions.

### `-fcommon[=<name>]`

Normally `asn1c` copies the ~69 "skeleton" runtime files in `/skeletons` (`BIT_STRING.c`,
`constr_SEQUENCE.c`, `asn_application.h`, etc) into the same directory as the
generated code. When you compile several specifications separately — RRC, NGAP and
XNAP each into their own directory — you get several redundant copies of an
identical runtime, and they can drift apart.

`-fcommon` puts one copy in a directory that is a **sibling of the `-D` directory**,
and points the generated `#include`s at it:

```
asn1c -D ./output/rrc  -fcommon ./rrc.asn1
asn1c -D ./output/ngap -fcommon ./ngap.asn1

output/
├── asn1c/          <- copied skeleton files, written once
│   ├── BIT_STRING.c
│   ├── constr_SEQUENCE.c
│   └── ...
├── rrc/            <- generated code only
│   ├── RRCSetup.c
│   └── ...
└── ngap/
    └── ...
```

Generated headers then refer to the skeleton files by relative path:

```c
#include "../asn1c/asn_application.h"
#include "../asn1c/NativeInteger.h"
```

Notes on behaviour:

- The common directory is a sibling of `-D`, not a child. With `-D ./output/rrc`
  the common directory is `./output/asn1c`, and the include prefix is always
  `../<name>/`.
- `-fcommon` without `-D` is an error: `-fcommon requires -D <destdir>`.
- If the common directory already exists, `asn1c` prompts
  `Overwrite existing files? [y/N]` on stderr and reads stdin. Anything other than
  `y`/`Y` — including EOF — aborts the run. **In a non-interactive script, redirect
  stdin (`< /dev/null`) only if you intend the run to abort**, or pre-remove the
  directory.
- Only the skeleton files move. `Makefile.am.libasncodec` is still written to the
  `-D` directory, with the common-directory files referenced by path.

### `-fprefix=<prefix>`

Prefixes generated **file names** so that output from several specifications can
share one directory or one include path without filename collisions:

```
$ asn1c -D out -fprefix=ASN_RRC_ rrc.asn1
$ ls out
ASN_RRC_T.c  ASN_RRC_T.h  ...
```

The include guard is prefixed to match (`_ASN_RRC_T_H_`). Skeleton runtime files
are **not** prefixed — they are shared, standard files.

**C identifiers are prefixed too**, which is what lets several specifications be
linked into one binary. The type above is `ASN_RRC_T_t`, its descriptor is
`asn_DEF_ASN_RRC_T`, and the same applies to `asn_MBR_*`, `asn_SPC_*`,
`asn_PER_*`, the per-type codec functions, `_PR` enumerators and `e_*` value
enumerations:

```c
typedef enum ASN_RRC_MyChoice_PR {
    ASN_RRC_MyChoice_PR_NOTHING,
    ASN_RRC_MyChoice_PR_a,
} ASN_RRC_MyChoice_PR;

typedef struct ASN_RRC_MyChoice {
    ASN_RRC_MyChoice_PR present;
    union ASN_RRC_MyChoice_u {
        ASN_RRC_MyInt_t  a;      /* prefixed: a user type */
        OCTET_STRING_t   b;      /* not prefixed: a skeleton type */
    } choice;
    asn_struct_ctx_t _asn_ctx;
} ASN_RRC_MyChoice_t;

extern asn_TYPE_descriptor_t asn_DEF_ASN_RRC_MyChoice;
```

Two things deliberately keep their unprefixed names:

- **Structure member names.** A member is scoped to its structure, and its name
  has to match between the declaration and every `offsetof()` that refers to it.
- **The copied skeleton runtime files.** `OCTET_STRING_t`, `asn_DEF_NativeInteger`,
  `asn_OP_SEQUENCE` and friends are one shared copy by design.

The ASN.1 names carried in descriptors for diagnostics (`"MyChoice"`) are also
left alone, so decoder output and XER remain unchanged.

---

## `asn1c_run.sh`

A convenience wrapper that invokes the locally built `asn1c/asn1c` with the flag
set these 3GPP specifications need. It fails early with a clear message if the
binary has not been built yet.

```
./asn1c_run.sh [OPTIONS] <file.asn1> [...]

  -D <dir>        Output directory (default: ./output)
  -p <prefix>     Passed through as -fprefix=<prefix>
  -c [<name>]     Passed through as -fcommon=<name> (default name: asn1c)
  --no-per        Add -no-gen-PER (PER is on by default)
  --no-oer        Add -no-gen-OER (OER is on by default)
  -h, --help      Show usage
```

Every invocation always passes:

```
-fcompound-names -pdu=all -findirect-choice -fno-include-deps -no-gen-example
```

### Why `-fcompound-names` and `-findirect-choice` are not optional

Both are required for 3GPP input. Omitting either produces a broken result, so they are worth
understanding before you invoke `asn1c` directly instead of through the wrapper.

**`-fcompound-names`** — 3GPP modules reuse short member names across nested
contexts. Without it, compiling `rrc-rel18-v18_9.asn1` aborts with 3421 name
clashes (`Name "ph_Type1or3" is generated by ... and ...`); `asn1c` diagnoses this
itself and tells you to pass the flag.

**`-findirect-choice`** — RRC's `SetupRelease {ElementTypeParam} ::= CHOICE`
is instantiated ~265 times, and every instantiation lands in a single
`SetupRelease.h`. That header includes each parameter type's header, and each of
those includes `SetupRelease.h` back. The include guard breaks the cycle in one
direction, so whichever file loses the race sees an incomplete `SetupRelease.h`
and fails with `unknown type name 'SetupRelease_3430P182_t'`.

`-findirect-choice` makes CHOICE members pointers, so a forward declaration
suffices and the cycle no longer needs resolving. Measured on
`rrc-rel18-v18_9.asn1` (2674 translation units, compiled with `gcc -fsyntax-only`):

| Flags | Failing TUs |
| ----- | ----------- |
| `-fcompound-names` only | 190 |
| `+ -fno-include-deps` | 99 |
| `+ -findirect-choice` | **0** |

This is inherent upstream behaviour for a mutually-recursive parameterized CHOICE,
not a defect introduced here: pristine upstream `asn1c` and this fork fail
identically on a five-line reduction of the pattern, and both are fixed by
`-findirect-choice`. `asn1c_run.sh` always passes it.

Examples:

```sh
./asn1c_run.sh -D ./output/rrc  .sample_asn1/rrc-rel18-v18_9.asn1
./asn1c_run.sh -p ASN_RRC_ -D ./output/rrc .sample_asn1/rrc-rel18-v18_9.asn1
./asn1c_run.sh -c -D ./output/ngap .sample_asn1/ngap-rel18-v18_9.asn1
```

---

## Bundled sample specifications

`.sample_asn1/` carries the 3GPP modules this fork was developed against:

| File | Spec |
| ---- | ---- |
| `rrc-rel18-v18_9.asn1` | NR RRC, Release 18 |
| `rrc-rel17-v3_0.asn1` | NR RRC, Release 17 |
| `ngap-rel18-v18_9.asn1` | NGAP, Release 18 |
| `xnap-rel18-v18_8.asn1` | XnAP, Release 18 |

All four compile, and the generated C compiles cleanly (verified with
`gcc -fsyntax-only` over every generated translation unit):

| Module | Generated TUs |
| ------ | ------------- |
| `rrc-rel18-v18_9` | 2674 |
| `rrc-rel17-v3_0` | 2098 |
| `xnap-rel18-v18_8` | 1394 |
| `ngap-rel18-v18_9` | 1266 |

NGAP and XnAP additionally require a 128-bit `asn1p_integer_t`; see
[Known limitations](#known-limitations).

---

## Parser and compiler changes

### Lexer

- **UTF-8 non-breaking space (`U+00A0`) is treated as whitespace.** Published 3GPP
  ASN.1 is extracted from formatted documents and contains stray non-breaking
  spaces that otherwise abort the parse.

### Grammar

- **Version brackets in CHOICE alternative lists.** A new `AlternativeTypeLists`
  production accepts `..., [[ ... ]]` extension groups inside a `CHOICE`, which
  3GPP uses heavily to add alternatives in later releases.
- **Modernised bison parameter passing.** The parser now uses `%parse-param {void
  **param}` instead of the obsolete `YYPARSE_PARAM` macro, which bison 3.x removed;
  `yyerror()` takes the parameter accordingly. This is a build-compatibility change
  with no effect on the language accepted.  Note this is readable by Bison 2.7, so
  for safety to comply with the upstream's REQUIREMENTS.md, that version of Bison
  can be used with the fork.

### Fixer

- **Tolerant information-object-class handling** (`libasn1fix/asn1fix_cws.c`).
  3GPP `WITH SYNTAX` object sets routinely reference values that asn1c cannot
  resolve to a top-level declaration — for example `reject` or `ignore`, which are
  members of an `ENUMERATED` such as `Criticality` rather than standalone values.
  Two changes:
  - Object-set content that does not match `WITH SYNTAX` is no longer fatal.
  - When a referenced value cannot be resolved directly, all modules are searched
    for an `ENUMERATED` member of that name before giving up. If it still cannot be
    resolved, the field assignment is skipped with a `WARNING` rather than aborting.

  This is why compiling the RRC modules emits a large number of warnings (~1389 for
  Release 18) rather than failing. The skipped assignments produce information
  object rows with no type, which the merged upstream open-type decoder fixes now
  handle safely instead of dereferencing a null pointer.

- **Parameterization specs are deep-copied** (`asn1p_expr_clone_impl`). `rhs_pspecs`
  is now cloned along with the rest of the expression, so forked parameterizations
  do not share mutable state.

### Information object set code generation

3GPP object sets exercise paths that produced C which would not compile. Three
fixes, all in the generator rather than the parser:

- **Duplicate CHOICE presence enumerators.** An object set may map several
  object identifiers onto one open type — three NGAP IE ids carry
  `TYPE NRUESidelinkAggregateMaximumBitrate` — yielding several CHOICE
  alternatives that share a type name and therefore an enumerator name. The
  union already collapsed these; the enumerator list did not. Repeats are now
  made unique (`X`, `X_2`, `X_3`) rather than dropped, because the decoder
  derives `presence_index` by counting alternatives and dropping one would
  renumber every later value.
- **Redefined `asn_VAL_*` constants.** These are named after the value rather
  than the object set, so every set sharing a value re-emitted an identical
  file-scope definition — 124 definitions of `asn_VAL_1_mandatory` in one
  file. Now emitted once per output file.
- **Unterminated object set cells.** A cell that could not be rendered was
  abandoned after its opening brace had been written, emitting
  `{ "&Value", ,`. Such cells arise from the skipped field assignments
  described above. An empty cell is now emitted instead, which the decoders
  already interpret as selecting no type.

A related mismatch is fixed alongside: the member table referenced
`asn_{OER,PER}_memb_*_constr_*` whenever a member carried constraints, while
the definition additionally required a constraint shape the generator can
describe. `OCTET STRING (CONTAINING X)` satisfies the first but not the
second, so the reference named a descriptor that was never emitted.

### Code generator

- **Member name `t` no longer collides with the typedef suffix**
  (`asn1c_naming.c`). An ASN.1 member literally named `t` generated
  `_<base>_t`, colliding with the generated `<base>_t` typedef; such members now
  get a trailing underscore.
- **Dependency matching strips directory prefixes** (`asn1c_fdeps.c`), so the
  relative include paths introduced by `-fcommon` still match dependency-chain
  basenames.
- **Skeleton includes route through a helper** (`asn1c_out.h`,
  `asn1c_skeleton_include_str`) so `-fcommon`'s relative paths survive; the previous
  macro built the include text in a way that collapsed `../` sequences.

---

## Aligned PER (APER)

The skeletons in this fork implement **aligned** PER alongside upstream's unaligned PER.  3GPP requires APER for NGAP and XnAP, while RRC uses UPER.

- `aper_encode()`, `aper_encode_to_buffer()`, `aper_encode_to_new_buffer()`,
  `aper_decode()`, `aper_decode_complete()` mirror their `uper_*` counterparts.
- `asn_TYPE_operation_t` carries `aper_decoder` / `aper_encoder` after the `uper`
  pair, and `asn_encode()` / `asn_decode()` accept `ATS_ALIGNED_BASIC_PER` and
  `ATS_ALIGNED_CANONICAL_PER`.
- No generator change is involved. Generated code references the `asn_OP_*`
  tables, so a module compiled by this fork will have both APER and UPER functionality avaialble.

Two things to know about the skeletons when making modifications:

- `asn_TYPE_operation_t` initialisers are **positional**. Any new op table needs
  all four PER slots, or entries after them silently shift — a table left at two
  PER slots puts `random_fill` where `aper_decoder` belongs.
- Types with no APER codec carry `0` in those slots; `aper_decode()` and
  `aper_encode()` check before dispatching.

The APER implementation was ported from the runtime shipped with
[UERANSIM](https://github.com/aligungr/UERANSIM), which used the same codec on
an older asn1c-generated RRC/NGAP file set.

---

## Known limitations

- **`asn1p_integer_t` must be 128-bit for NGAP/XnAP.** Both use
  `INTEGER (0..18446744073709551615)` — `UINT64_MAX` — which does not fit the
  64-bit `intmax_t` fallback and aborts the parse with
  `Value "18446744073709551615" ... is too large for this compiler`.
  `configure` selects `__int128` via `AC_CHECK_TYPE([__int128])`, so an
  autotools build on any mainstream 64-bit target is fine; a hand-rolled build
  that does not define `HAVE_128_BIT_INT` is not. Check `config.h` if you hit
  this.

---

## Building

Standard upstream build:

```sh
autoreconf -iv && ./configure && make && make install
```

### Regenerating the parser

`libasn1parser/asn1p_y.c`, `asn1p_y.h`, `asn1p_y.output` and `asn1p_l.c` are
checked in, so a plain build needs neither bison nor flex. If you change the
grammar or the lexer, regenerate with the versions that produced the committed
files — **GNU Bison 3.8.2** reproduces `asn1p_y.c` byte-identically:

```sh
cd libasn1parser
bison -p asn1p_ -d -v -o asn1p_y.c asn1p_y.y     # matches AM_YFLAGS
```

The grammar should report **4 shift/reduce and 2 reduce/reduce conflicts**, the
same counts as upstream. A higher count means a newly added rule is shadowing an
existing production rather than extending the language — bison resolves
shift/reduce in favour of shift, so the new rule silently wins and the original
becomes unreachable. Run `bison -Wcounterexamples` to see exactly which
productions are in conflict.

### Tests

```sh
make check
```

The full suite passes (exit 0, no failures). `tests/tests-asn1c-compiler` passes
**131/131**; `tests/tests-c-compiler` passes 46 of 47 with one expected failure
(`check-158`).

Note that `tests-asn1c-compiler` only compares generated text — it never
compiles what it generates. Four of its expectations previously recorded C that
does not compile (a duplicated `value_PR_BOOLEAN` enumerator, and
`{ "&Type", ,` cells) and were regenerated when those bugs were fixed. When
changing the generator, compile the output of the bundled 3GPP modules as well;
that is what actually catches this class of defect.
