//2.9 Explicit Type Conversion of Addresses
#include <stdio.h>
#include <stdint.h>

typedef unsigned char UBYTE;

int main(void) {
    // Simulated memory
    UBYTE memory[0x2000];      
    memory[0x1000] = 0xAB;     // put a test value at "address" 0x1000

    // Create a pointer to that "address"
    UBYTE *ptr = &memory[0x1000];

    // Read value into variable
    UBYTE target = *ptr;

    printf("Value at 0x1000 = 0x%X\n", target);

    return 0;
}