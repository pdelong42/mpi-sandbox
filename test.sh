#!/bin/sh

set -euo pipefail

MPIRUN=/usr/local/software/OpenMPI/openmpi-2.0.0/bin/mpirun

test -z "${NODES:-}" && NODES=10
test -z "${PPN:-}"   && PPN=28

PROGFILE=${1:-}

if test -z "$PROGFILE" ; then
   echo "first arg should be the name of the program to be run"
   exit 1
fi

QSUB="qsub -I -q batch -l nodes=${NODES}:ppn=${PPN} -l walltime=08:00:00"
MPICMD="$MPIRUN --mca btl ^tcp -np $(( $NODES * $PPN )) $(realpath $PROGFILE)"

$QSUB -- $MPICMD
