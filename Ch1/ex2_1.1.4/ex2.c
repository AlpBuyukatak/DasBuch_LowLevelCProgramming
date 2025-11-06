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
    unsigned char c = 0x93;  // 1001 0011 (147)
    unsigned int i = c;      // 4 byte int

    printf("unsigned char (8 bit): ");
    print_bits(c, 8);

    printf("unsigned int  (32 bit): ");
    print_bits(i, 32);

    return 0;
}