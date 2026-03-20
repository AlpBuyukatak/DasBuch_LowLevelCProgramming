/* 11.3: Solution Approach (dump routine)
- Output is blockwise (e.g., 16 lines per block, 16 bytes per line).
- After each block, wait for a key; if '-' is entered, terminate.
- For each line: print address + numeric hex area + ASCII area.
Bu kod, verilen bir bellek adresinden başlayarak belleği blok blok okur; 
her satırda adres, byte’ların hex değerleri ve ASCII karşılıklarını birlikte ekrana yazdırır, 
her bloktan sonra kullanıcıdan devam/çıkış girdisi bekler.
*/

#include <stdio.h>

typedef unsigned char  UBYTE;
typedef unsigned short WORD;
typedef unsigned long  ULONG;

#define LINES_PER_BLOCK 16
#define BYTES_PER_LINE  16

static char ascii_or_dot(UBYTE b) { return (b >= 32 && b <= 126) ? (char)b : '.'; }

void dump(const UBYTE *adr, WORD fmt) {
    int reaction;

    do {
        for (int line=0; line<LINES_PER_BLOCK; line++, adr += BYTES_PER_LINE) {
            /* address */
            printf("%08lX  ", (ULONG)adr);

            /* numeric area (minimal: BYTE format only for core idea) */
            for (int i=0;i<BYTES_PER_LINE;i++) printf("%02X ", adr[i]);

            /* ASCII area */
            printf(" | ");
            for (int i=0;i<BYTES_PER_LINE;i++) putchar(ascii_or_dot(adr[i]));
            putchar('\n');
        }

        printf("Weiter? (- to quit) ");
        reaction = getchar();
        while (reaction!='\n' && getchar()!='\n') { /* flush */ }

    } while (reaction != '-');
}

int main(void) {
    /* demo memory */
    static UBYTE demo[256];
    for (int i=0;i<256;i++) demo[i] = (UBYTE)i;

    dump(demo, 1);
    return 0;
}
