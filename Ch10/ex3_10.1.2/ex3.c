#include <stdio.h>

typedef unsigned char BYTE;

/* 10.1.2: Basic copy algorithm
   - first copy current character
   - test for null byte
   - increment both pointers
*/

BYTE *strcpy_solution1(BYTE *ziel, const BYTE *quelle)
{
    BYTE *save = ziel;

    *ziel = *quelle;
    while (*ziel != 0) {
        ziel   = ziel   + 1;
        quelle = quelle + 1;
        *ziel  = *quelle;
    }

    return save;
}

int main(void)
{
    const BYTE src[] = "ABC";
    BYTE dst[16];

    strcpy_solution1(dst, src);
    printf("dst = %s\n", (char *)dst);

    return 0;
}
