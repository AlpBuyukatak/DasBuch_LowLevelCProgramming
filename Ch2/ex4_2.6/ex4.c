//2.6 Explicit Type Conversion - page 33
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