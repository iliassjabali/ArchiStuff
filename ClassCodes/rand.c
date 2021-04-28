#include <stdio.h>

static unsigned long seed = 0, multiplier = 9089, adder = 7237;

// A standard pseudo-random number generator takes a "seed" value,
// and then generates more values with the formula:
//		newseed = seed * multiplier + adder

int myrand(){	

        asm( //"movl %0, %%eax\n"
			 "mull %1\n"   // multiply a by "mult", store result in d:a
			 "addl %2, %%eax\n" // add "adder"
			 //"movl %%eax, %0\n"
		: "=a" (seed)
		: "a" (seed), "b" (multiplier), "c"(adder)
		);
		return seed;
}

int main(int argc, char **argv) // use command line arguments
								// to set the random number seed
{
	char c;
	if(argc == 2) {sscanf(argv[1], "%d", &seed);}
	do{
		printf("%d\n", myrand());
		}
	while (getchar() != 'q');
}