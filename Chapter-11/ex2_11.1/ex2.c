/* 11.1: Mode of Operation (format selection + ASCII rule)
Memory can be displayed as 1-byte, 2-byte, or 4-byte values.
ASCII: only printable chars (32..126) shown; others replaced by '.'.
------------------------
Aynı bellek içeriğini, seçilen moda göre (BYTE / WORD / LONG) farklı biçimlerde ekrana yazdırıyor 
ve yanında ASCII karşılığını gösteriyor.
*/

#include <stdio.h>
#include <ctype.h>

typedef unsigned char  UBYTE;
typedef unsigned short WORD;
typedef unsigned long  ULONG;

static char ascii_or_dot(UBYTE b) { return (b >= 32 && b <= 126) ? (char)b : '.'; }

int main(void) {
    UBYTE bytes[16] = { 0x01,0x02,0x03,0x04,  0x41,0x42,0x43,0x44,  0x10,0x20,0x30,0x40,  0x7E,0x7F,0x80,0x81 };
    int fmt = 1; /* 1=BYTE, 2=WORD, 4=LONG */

    /* Read format char like the book: b/w/l */
    printf("Format (b/w/l): ");
    int ch = tolower(getchar());
    if (ch == 'w') fmt = 2;
    else if (ch == 'l') fmt = 4;

    /* Print numeric area depending on fmt */
    if (fmt == 1) {
        for (int i=0;i<16;i++) printf("%02X ", bytes[i]);
    } else if (fmt == 2) {
        for (int i=0;i<16;i+=2) {
            WORD w = (WORD)(bytes[i] | ((WORD)bytes[i+1] << 8));
            printf("%04X ", w);
        }
    } else {
        for (int i=0;i<16;i+=4) {
            ULONG L = (ULONG)bytes[i]
                    | ((ULONG)bytes[i+1] << 8)
                    | ((ULONG)bytes[i+2] << 16)
                    | ((ULONG)bytes[i+3] << 24);
            printf("%08lX ", L);
        }
    }

    /* ASCII area always bytewise */
    printf(" | ");
    for (int i=0;i<16;i++) putchar(ascii_or_dot(bytes[i]));
    putchar('\n');

    return 0;
}
