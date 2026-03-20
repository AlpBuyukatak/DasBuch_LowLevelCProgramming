//1.4 Type Definition - page 23
/*
This code defines UWORD as an exact 16-bit unsigned type (uint16_t), assigns it the value 0xABCD, 
and prints it in hexadecimal form. It demonstrates how to use fixed-width integer types with typedef.
*/
#include <stdio.h>
#include <stdint.h>   // dont forget to add this library

typedef uint16_t UWORD;   // exact 16 bit 

int main() {
    UWORD value = 0xABCD;

    printf("UWORD value: 0x%X\n", value);

    return 0;
}
