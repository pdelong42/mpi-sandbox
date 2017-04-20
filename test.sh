#!/bin/sh

set -euo pipefail

MPIRUN=/usr/local/software/OpenMPI/openmpi-2.0.0/bin/mpirun
NODES=10
PPN=28
NP=$(( $NODES * $PPN ))

PROGFILE=${1:-}

if test -z "$PROGFILE" ; then
   echo "first arg should be the name of the program to be run"
   exit 1
fi

PROGPATH=$(realpath $PROGFILE)

qsub -I -q batch -l nodes=${NODES}:ppn=${PPN} -l walltime=08:00:00 -- \
$MPIRUN --mca btl '^tcp' -np $NP $PROGPATH
