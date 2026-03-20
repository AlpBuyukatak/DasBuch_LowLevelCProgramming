//2.9 Explicit Type Conversion of Addresses - page 40
/*
This code simulates memory with a byte array, writes a 16-bit value at a specific index, 
and then reads it back using a base pointer plus an offset, showing how pointer arithmetic 
and casting let you access multi-byte data inside raw memory.
*/
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