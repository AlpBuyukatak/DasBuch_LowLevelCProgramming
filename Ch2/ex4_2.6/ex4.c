//2.6 Explicit Type Conversion - page 33
/*
This code shows how different integer constant suffixes (L, U, UL) affect the 
type of the literal 0xFFFF, but all three still fit into a long, 
so each variable ends up storing the same numeric value when printed.
*/

#include <stdio.h>

int main(void) {
    long longx = 0xFFFFL;        // long constant
    long longy = 0xFFFFU;        // unsigned int constant (assigned to long)
    long longz = 0xFFFFUL;       // unsigned long constant (assigned to long)

    printf("longx = %ld\n", longx);
    printf("longy = %ld\n", longy);
    printf("longz = %ld\n", longz);

    return 0;
}