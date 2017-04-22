#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <math.h>

int main( int argc, char **argv ) {

    int my_rank, num_procs;

    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );
    MPI_Comm_size( MPI_COMM_WORLD, &num_procs );

    if( my_rank == 0 ) {

        double buf1 = 1.23456789;

        printf( "We have %i processes.\n", num_procs );

        printf( "root node, before: %f\n", buf1 );
        MPI_Bcast( &buf1, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
        printf( "root node, after:  %f\n", buf1 );

    } else {

        double buf2 = M_PI;

        printf( "child node, before: %f\n", buf2 );
        MPI_Bcast( &buf2, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
        printf( "child node, after:  %f\n", buf2 );
    }

    MPI_Finalize();
}
