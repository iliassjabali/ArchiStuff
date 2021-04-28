#include <stdio.h>


int main(void) {

    int arg1, arg2, sum, dif, prod, quo, rem ;

    printf( "Enter two integer numbers : " );
    scanf( "%d%d", &arg1, &arg2 );

    /* Perform Addition, Subtraction, Multiplication & Division */
    __asm__ ( "addl %%ebx, %%eax;"  
			: "=a" (sum) // put the value @ reg a in the variable sum 
			: "a" (arg1) , "b" (arg2)  // assign the arg 1 to  a and b to arg2
			);
    __asm__ ( "subl %%ebx, %%eax;" : "=a" (dif) : "a" (arg1) , "b" (arg2) );
    __asm__ ( "imull %%ebx, %%eax;" : "=a" (prod) : "a" (arg1) , "b" (arg2) );

    __asm__ ( "movl $0, %%edx;"
              "movl %2, %%eax;"
              "movl %3, %%ebx;"
              "idivl %%ebx;" 
			   : "=a" (quo), "=d" (rem) 
			   : "a" (arg1), "b" (arg2) );

    printf( "%d + %d = %d\n", arg1, arg2, sum );
    printf( "%d - %d = %d\n", arg1, arg2, dif );
    printf( "%d * %d = %d\n", arg1, arg2, prod );
    printf( "%d / %d = %d\n", arg1, arg2, quo );
    printf( "%d %% %d = %d\n", arg1, arg2, rem );

    return 0 ;
}