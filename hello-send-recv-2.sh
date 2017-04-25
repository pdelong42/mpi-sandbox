#!/bin/sh

set -xeuo pipefail

TEST=$(realpath test.sh)
EXE=$(basename ${0/.sh})
RUN="$TEST $EXE"

$RUN
