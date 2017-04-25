#include <stdio.h>

int factorial( unsigned int n ) {
    if( n == 0 ) return 1;
    return( n * factorial( n - 1 ) );
}

int main( int argc, char **argv ) {

    int n = 0;

    while( n < 280 ) {
        printf( "1/factorial(%d) = %.30lf\n", n, 1/(double)factorial( n ) );
        ++n;
    }
}
