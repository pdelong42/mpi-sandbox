qsub -I -q batch -l nodes=10:ppn=28 -l walltime=08:00:00 -- /usr/local/software/OpenMPI/openmpi-2.0.0/bin/mpirun --mca btl '^tcp' -np 280 /home/pdelong/HELLO_RUNS/$1
