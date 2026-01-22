#include <stdio.h>

typedef unsigned char BYTE;

/* 10.1.2: Optimized strcpy version
   - register pointers
   - increment as side effect
   - empty while body
*/

BYTE *strcpy_final(register BYTE *ziel, register const BYTE *quelle)
{
    register BYTE *save = ziel;

    while (*ziel++ = *quelle++)
        ;

    return save;
}

int main(void)
{
    BYTE dst[64];
    strcpy_final(dst, (const BYTE *)"Pointer copy");

    printf("%s\n", (char *)dst);
    return 0;
}
