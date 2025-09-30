#include <stdio.h>
#include <stdint.h>

typedef unsigned char  BYTE;
typedef unsigned short WORD;

int main(void) {
    BYTE memory[1024] = {0};

    BYTE *basis  = &memory[100];   // taban adresi işaretçi
    BYTE  offset = 10;

    *( (WORD *)(memory + 110) ) = 0xABCD;   // örnek veri yaz

    WORD value = *( (WORD *)(basis + offset) ); // basis+offset adresinden WORD oku

    printf("Read value = 0x%04X\n", value);
    return 0;
}