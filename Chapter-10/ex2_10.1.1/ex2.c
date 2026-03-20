#include <stdio.h>

typedef unsigned char BYTE;

/* 10.1.1: strcpy prototype
   - source is const
   - destination returned as result
*/

BYTE *my_strcpy(BYTE *ziel, const BYTE *quelle)
{
    BYTE *save = ziel;

    while ((*ziel++ = *quelle++) != 0)
        ;

    return save;
}

int main(void)
{
    BYTE dst[32];

    printf("%s\n", (char *)my_strcpy(dst, (const BYTE *)"OK"));
    return 0;
}
