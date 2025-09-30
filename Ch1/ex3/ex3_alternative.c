//1.4 Type Definition
#include <stdio.h>
#include <stdint.h>   // <--- önemli

typedef uint16_t UWORD;   // exact 16 bit

int main() {
    UWORD value = 0xABCD;

    printf("UWORD value: 0x%X\n", value);

    return 0;
}