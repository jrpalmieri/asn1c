#!/usr/bin/env bash
# Run asn1c on one or more 3GPP R17/R18 ASN.1 files.
#
# Usage:
#   ./asn1c_run.sh [OPTIONS] <file.asn1> [...]
#
# Options:
#   -D <dir>          Output directory (default: ./output)
#   -p <prefix>       Prepend prefix to all generated type/file names
#   -c [<name>]       Use common directory for skeleton files (default name: asn1c)
#   --no-per          Disable PER support code (default: enabled)
#   --no-oer          Disable OER support code (default: enabled)
#   -h, --help        Show this message
#
# Examples:
#   ./asn1c_run.sh -D ./output/ngap  .sample_asn1/ngap-rel18-v18_9.asn1
#   ./asn1c_run.sh -p ASN_RRC_ -D ./output/rrc  .sample_asn1/rrc-rel18-v18_9.asn1
#   ./asn1c_run.sh -D ./out/xnap .sample_asn1/xnap-rel18-v18_8.asn1
#   ./asn1c_run.sh -c -D ./output/ngap .sample_asn1/ngap-rel18-v18_9.asn1
#   ./asn1c_run.sh -c mydir -D ./output/ngap .sample_asn1/ngap-rel18-v18_9.asn1

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
ASN1C="${SCRIPT_DIR}/asn1c/asn1c"
SKELETONS="${SCRIPT_DIR}/skeletons"

if [ ! -x "$ASN1C" ]; then
    echo "ERROR: asn1c binary not found at $ASN1C" >&2
    echo "       Run 'make' in $SCRIPT_DIR first." >&2
    exit 1
fi

OUTPUT_DIR="./output"
PREFIX=""
COMMON_DIR=""
GEN_PER=1
GEN_OER=1
ASN_FILES=()

usage() {
    sed -n '3,21p' "$0"
    exit 0
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        -D) OUTPUT_DIR="$2"; shift 2 ;;
        -D*) OUTPUT_DIR="${1#-D}"; shift ;;
        -p) PREFIX="$2"; shift 2 ;;
        -p*) PREFIX="${1#-p}"; shift ;;
        -c)
            # -c may be followed by an optional name (not starting with -)
            if [[ $# -gt 1 && "$2" != -* && "$2" != *.asn* ]]; then
                COMMON_DIR="$2"; shift 2
            else
                COMMON_DIR="asn1c"; shift
            fi ;;
        -c*) COMMON_DIR="${1#-c}"; [ -z "$COMMON_DIR" ] && COMMON_DIR="asn1c"; shift ;;
        --no-per) GEN_PER=0; shift ;;
        --no-oer) GEN_OER=0; shift ;;
        -h|--help) usage ;;
        -*) echo "Unknown option: $1" >&2; exit 1 ;;
        *) ASN_FILES+=("$1"); shift ;;
    esac
done

if [ ${#ASN_FILES[@]} -eq 0 ]; then
    echo "ERROR: No ASN.1 files specified." >&2
    usage
fi

mkdir -p "$OUTPUT_DIR"

ASNOPTS=(
    -fcompound-names
    -pdu=all
    -findirect-choice
    -fno-include-deps
    -fhave_native64
    -no-gen-example
    -S "$SKELETONS"
    -D "$OUTPUT_DIR"
)

[ -n "$PREFIX" ] && ASNOPTS+=("-fprefix=${PREFIX}")
[ -n "$COMMON_DIR" ] && ASNOPTS+=("-fcommon=${COMMON_DIR}")
[ "$GEN_PER" -eq 0 ] && ASNOPTS+=("-no-gen-PER")
[ "$GEN_OER" -eq 0 ] && ASNOPTS+=("-no-gen-OER")

echo "Running: $ASN1C ${ASNOPTS[*]} ${ASN_FILES[*]}"
"$ASN1C" "${ASNOPTS[@]}" "${ASN_FILES[@]}"

echo ""
echo "Generated files in: $OUTPUT_DIR"
echo "C source files: $(find "$OUTPUT_DIR" -maxdepth 1 -name '*.c' ! -name 'converter-example.c' | wc -l)"
