//2.6 Explicit Type Conversion - page 32
//its an example code 
#include <stdio.h>
#include <stdint.h>

int main(void) {
    int longx1 = (short) 0xFFFF;     // treated as signed 16-bit → -1
    long longx2 = (long) 0xFFFF;     // treated as long (signed, but wider) → 65535
    unsigned long longz = (unsigned long) 0xFFFF; // treated as unsigned → 65535

    printf("longx1 = %d\n", longx1);       // -1
    printf("longx2 = %ld\n", longx2);      // 65535
    printf("longz  = %lu\n", longz);       // 65535

    return 0;
}