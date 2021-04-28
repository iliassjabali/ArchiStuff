#include <stdio.h>


int main (void){
    
    int arg[3], res =0;
    arg[0] = 3, arg[1] = 2, arg[2] = 8;

    asm(
        " imull %%eax, %%ebx; "
        " addl %%ebx, %%ecx; "
        : "=c" (res) 
        : "a" (arg[0]), "b" (arg[1]), "c" (arg[2])
    );
    printf("%d", res);
    return 0;
}