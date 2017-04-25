#!/bin/sh

set -xeuo pipefail

TEST=$(realpath test.sh)
EXE=$(basename ${0/.sh})
RUN="$TEST $EXE"

env NODES=2 PPN=2 $RUN
