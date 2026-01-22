/* 11.0: Memory Dump (core idea)
Display memory contents bytewise in hexadecimal and ASCII so that
data and embedded text can be recognized during debugging.
*/

#include <stdio.h>

typedef unsigned char UBYTE;

static char ascii_or_dot(UBYTE b) { return (b >= 32 && b <= 126) ? (char)b : '.'; }

int main(void) {
    UBYTE data[16] = { 0x48,0x65,0x6C,0x6C,0x6F,0x00,0x01,0x7F,0x41,0x42,0x43,0x20,0x2E,0xFF,0x10,0x0A };

    /* Print bytes as HEX */
    for (int i = 0; i < 16; i++) printf("%02X ", data[i]);
    printf(" | ");

    /* Print bytes as ASCII (non-printable -> '.') */
    for (int i = 0; i < 16; i++) putchar(ascii_or_dot(data[i]));
    putchar('\n');

    return 0;
}
