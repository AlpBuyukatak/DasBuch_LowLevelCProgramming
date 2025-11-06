//1.1.4 Sign Attributes - page 18
#include <stdio.h>
#include <stdint.h>

void print_bits(unsigned int value, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i % 4 == 0) printf(" "); // space for readability 
    }
    printf("\n");
}

int main() {
    signed char c = 0x93;  // 1001 0011
    short int i = c;       // 2 byte int

    printf("char (8 bit):   ");
    print_bits((unsigned char)c, 8);

    printf("short (16 bit): ");
    print_bits((unsigned short)i, 16);

    return 0;
}