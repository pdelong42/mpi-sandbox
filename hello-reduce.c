#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>
#include <math.h>

/*

An example of MPI_Reduce(), by way of generating Euler's constant.

This is a highly contrived example of how MPI_Reduce() works.  I'm hard pressed
to think of a situation in which one would actually use it in such a simplistic
fashion.  But it gets the idea across with as few lines of code as I could
think of.

Additionally, there is a severe limitation: you should spawn no more than 32-33
instances across nodes/processors in the cluster, because higher than that and
this code will fail specacularly.  After the 32nd or 33rd term, the value
vanishes below the smallest representable double-precision number.  For reasons
that aren't clear to me, this is represented as "inf" rather than "0.0", which
is counter-intuitive to me.  I leave it as an exercise for the reader (and for
myself) to find-out why.

*/

int factorial( unsigned int n ) {
    if( n == 0 ) return 1;
    return( n * factorial( n - 1 ) );
}

int main( int argc, char **argv ) {

    int my_rank, num_procs;

    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );
    MPI_Comm_size( MPI_COMM_WORLD, &num_procs );

    double euler, term;

    if( my_rank == 0 ) {

        printf( "We have %i processes.\n", num_procs );

        MPI_Reduce( &term, &euler, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD );
        printf( "accumulated sum: %.30f\n", 1 + euler );

    } else {

        term = 1 / (double)factorial( my_rank );

        printf( "term #%d: %.30f\n", my_rank, term );
        MPI_Reduce( &term, &euler, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD );
    }

    MPI_Finalize();
}
