// This sample program from a standard online library illustrates 
// the use of assembly language in implementing a standard string 
// library function, strcpy.
#include <stdio.h>

static inline char * strcpy(char * dest,const char *src) {
	int d0, d1, d2; // The use of these variables makes it possible
					// to observe what is happening in the 
					// assembly code while running the program with
					// a debugger.
	__asm__ (  
		   "1:lodsb\n" 			// load from DS:SI into AX, inc SI
           "stosb\n"			// store into DS:DI from AX, inc DI
           "testb %%al,%%al\n" 	// check for 0 character (end of string)
           "jne 1b"
        : "=&S" (d0), "=&D" (d1), "=&a" (d2)
        : "0" (src),"1" (dest) 
        : "memory");
	return dest;
}

void main() {
	char s2[10], *s1 = "check";
	strcpy(s2, s1);
		s2 = s1; 
	printf("New string is: %s\n", s2);
}