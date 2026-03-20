#include <stdio.h>

typedef unsigned char BYTE;

/* 10.1.2: implicit zero test in C
   - assignment expression controls loop
   - loop terminates when '\0' is copied
*/

BYTE *strcpy_no_compare(BYTE *ziel, const BYTE *quelle)
{
    BYTE *save = ziel;

    while ((*ziel++ = *quelle++))
        ;

    return save;
}

int main(void)
{
    BYTE dst[32];
    strcpy_no_compare(dst, (const BYTE *)"Test");

    printf("%s\n", (char *)dst);
    return 0;
}
