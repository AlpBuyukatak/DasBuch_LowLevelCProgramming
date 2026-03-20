//2.9 Explicit Type Conversion of Addresses - page 39
/*
This code simulates memory using an array, stores a byte at index 0x1000, 
then uses a pointer to read that byte back into a variable. It demonstrates 
how pointers can access specific “memory addresses” inside an array.
*/

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