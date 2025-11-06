//1.4 Type Definition - page 23
#include <stdio.h>
#include <stdint.h>   // dont forget to add this library

typedef uint16_t UWORD;   // exact 16 bit 

int main() {
    UWORD value = 0xABCD;

    printf("UWORD value: 0x%X\n", value);

    return 0;
}