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

        double dst;

        printf( "We have %i processes.\n", num_procs );

        MPI_Recv( &dst, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
        printf( "root node received: %f\n", dst );

    } else {

        double src = M_PI;

        printf( "child node sending: %f\n", src );
        MPI_Send( &src, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD );
    }

    MPI_Finalize();
}
