//2.9 Explicit Type Conversion of Addresses - page 39
/* byte will be read from address 0x1000.
This value will be written to both addresses 0x00008000 and 0xFFFF8000. 
*/
#include <stdio.h>
#include <stdint.h>

typedef unsigned char BYTE;

int main(void) {
    BYTE memory[0x10000] = {0}; // simulate 64KB memory

    // put test value at address 0x1000
    memory[0x1000] = 0xAB;

    // read from 0x1000 and write to 0x8000
    memory[0x8000] = memory[0x1000];

    // read from 0x1000 and write to 0xFFFF8000 equivalent (simulate with wrap)
    memory[0x8000] = memory[0x1000]; // simplified simulation

    printf("Value at 0x1000 = 0x%X\n", memory[0x1000]);
    printf("Value at 0x8000 = 0x%X\n", memory[0x8000]);

    return 0;
}
