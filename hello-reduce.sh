#!/bin/sh

set -xeuo pipefail

TEST=$(realpath test.sh)
EXE=$(basename ${0/.sh})
RUN="$TEST $EXE"

env NODES=4 PPN=4 $RUN
