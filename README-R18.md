# asn1c-r18 — fork notes

This is a fork of [vlm/asn1c](https://github.com/vlm/asn1c) adapted to compile the
3GPP ASN.1 specifications for **RRC, NGAP and XNAP up to Release 18**.

Everything in upstream asn1c works as documented in [README.md](README.md); this
file covers **only what the fork adds or changes**. Upstream is merged in through
v0.9.29 plus its post-release fixes (including CVE-2025-32893).

---

## Added command-line options

Four options are added to `asn1c`. All are spelled `-f<name>`, matching upstream's
convention for compiler flags.

| Option | Effect |
| ------ | ------ |
| `-fcommon` | Write skeleton/support files to a shared directory named `asn1c` instead of into the `-D` output directory. Requires `-D`. |
| `-fcommon=<name>` | As above, using `<name>` for the directory. An empty `<name>` falls back to `asn1c`. |
| `-fprefix=<prefix>` | Prepend `<prefix>` to generated **output file names** and their include guards. |
| `-fhave_native64` | Accepted and parsed, but **currently has no effect** — see [Known limitations](#known-limitations). |

Note that `asn1c -h` lists only `-fprefix` and `-fhave_native64`. `-fcommon` works
but is missing from the built-in help, and the `-fprefix` entry overstates what it
does; this file is the accurate reference.

### `-fcommon[=<name>]`

Normally `asn1c` copies the ~69 skeleton runtime files (`BIT_STRING.c`,
`constr_SEQUENCE.c`, `asn_application.h`, …) into the same directory as the
generated code. When you compile several specifications separately — RRC, NGAP and
XNAP each into their own directory — you get several redundant copies of an
identical runtime, and they can drift apart.

`-fcommon` puts one copy in a directory that is a **sibling of the `-D` directory**,
and points the generated `#include`s at it:

```
asn1c -D ./output/rrc  -fcommon ./rrc.asn1
asn1c -D ./output/ngap -fcommon ./ngap.asn1

output/
├── asn1c/          <- skeleton runtime, written once
│   ├── BIT_STRING.c
│   ├── constr_SEQUENCE.c
│   └── ...
├── rrc/            <- generated code only
│   ├── RRCSetup.c
│   └── ...
└── ngap/
    └── ...
```

Generated headers then refer to the runtime by relative path:

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

> **Scope — read this before relying on it.** `-fprefix` renames files and include
> guards **only**. C identifiers are left untouched: the type above is still
> `T_t`, and its descriptor is still `asn_DEF_T`. The option therefore prevents
> *filename* collisions but **not** *symbol* collisions, so it does not by itself
> let you link two specifications that define the same type name into one binary.
> The built-in `--help` text claims it also prefixes "generated struct/type names";
> that text is inaccurate.

### `-fhave_native64`

Intended to select `int64_t`/`uint64_t` for the target platform. It is accepted on
the command line and sets the `A1C_HAVE_NATIVE_64` flag bit, but **nothing in the
compiler reads that bit**, so output is byte-for-byte identical with and without
it. It is currently a no-op, retained for command-line compatibility with existing
scripts (`asn1c_run.sh` passes it).

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
-fcompound-names -pdu=all -findirect-choice -fno-include-deps
-fhave_native64 -no-gen-example
```

### Why `-fcompound-names` and `-findirect-choice` are not optional

Both are load-bearing for 3GPP input. Neither is fork-specific — they are stock
upstream options — but omitting either produces a broken result, so they are worth
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

`.sample_asn1/` carries the 3GPP modules this fork is developed against:

| File | Spec |
| ---- | ---- |
| `rrc-rel18-v18_9.asn1` | NR RRC, Release 18 |
| `rrc-rel17-v3_0.asn1` | NR RRC, Release 17 |
| `ngap-rel18-v18_9.asn1` | NGAP, Release 18 |
| `xnap-rel18-v18_8.asn1` | XnAP, Release 18 |

The two RRC modules compile. NGAP and XnAP currently do not — see
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
  with no effect on the language accepted.

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

## Known limitations

- **NGAP and XnAP do not compile.** Both abort at parse time on
  `Value "18446744073709551615" ... is too large for this compiler` —
  `18446744073709551615` is `UINT64_MAX`, which exceeds the range of the parser's
  `asn1p_integer_t`. This is unrelated to the 3GPP-specific changes above and blocks
  those two specifications entirely.
- **`-fprefix` does not prefix C identifiers**, only filenames and include guards
  (see above). The built-in help text overstates its scope.
- **`-fhave_native64` is a no-op** (see above).
- **`-fcommon` is undocumented in `asn1c -h`.**

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

The `tests/tests-asn1c-compiler` suite compares compiler output against checked-in
expectations and should pass **131/131**, matching upstream.
