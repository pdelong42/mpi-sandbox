#!/bin/sh

set -euo pipefail

NODES=10
PPN=28
NP=$(( $NODES * $PPN ))

qsub -I -q batch -l nodes=${NODES}:ppn=${PPN} -l walltime=08:00:00 -- \
/usr/local/software/OpenMPI/openmpi-2.0.0/bin/mpirun --mca btl '^tcp' -np $NP ${HOME}/HELLO_RUNS/$1

# ToDo:
# - add input parameter checking
# - try to parameterize the full path of the executable
