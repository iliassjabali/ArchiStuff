#include <stdio.h>

float square_root( float val ) {
    float result ;
    __asm__ __volatile__ (  "fld %1;"
                            "fsqrt;"
                            "fstp %0;" : "=m" (result) : "m" (val)
    ) ;
    return result ;
}


int main() {
    float theta ;
    printf( "Enter theta in degrees : " ) ;
    scanf( "%f", &theta ) ;

    printf( "square_root(%f) = %f\n", theta, square_root( theta ) ) ;

    return 0 ;
}