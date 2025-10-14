#include <stdio.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;

int main(void) {
    WORD intx = 0x1234;   // 0x12 = high byte, 0x34 = low byte
    BYTE val1 = intx;     // val1 = 0x34 (low byte)
    BYTE val2 = *( (BYTE *)&intx ); // val2 = 0x34 (for Intel system low byte)

    printf("val1 = 0x%X\n", val1);
    printf("val2 = 0x%X\n", val2);
    return 0;
}