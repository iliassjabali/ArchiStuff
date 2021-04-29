// test.c
#include <stdio.h>

// Register types: AL, AX, EAX, 
//					SP, ESP
// Compile with gcc -S test.c

char *s = "(number)";
void main() {
					// call to _main
	int i, num = 2;

	long int l[50];
	
	l[0] = l[num] + 13;
	
	for(i = 100; i > 0; i--) {
					// load 'i' into a register
					// store $100 into the register
					// label: jump back to here
					// compare the register to 0
					// jump past end of loop if register negative
		
		num *= num; // load 'num' into a register
					// multiply register by 'num'
					// save register to 'num'
		
		if(i%2 != 0)
					// divide by 2, get remainder
					// compare to 0
					// jump past print if equal to zero
			printf("Odd! %s", s);
					// call _printf
					
					// label: jump to here
					// decrement i
					// jump back to start of loop
	}
}