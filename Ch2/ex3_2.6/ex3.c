//2.6 Explicit Type Conversion - page 32
//its an example code 
/*
This code shows how the same hex value 0xFFFF produces different results depending
on the cast: as a signed 16-bit value it becomes -1, while casting to wider signed 
or unsigned types preserves it as 65535.
*/
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