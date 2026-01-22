/* ex10_12.c — 10.3.3: xtol (hex conversion) */

#include <stdio.h>

typedef unsigned char BYTE;
typedef signed short  WORD;
typedef signed long   LONG;

/* 10.3.3: Converting characters into a hexadecimal number — xtol
   validity: '0'..'9' OR 'A'..'F' OR 'a'..'f'
   inside: compute val, then sum = sum*16 + val
*/
LONG xtol(register const BYTE *quelle)
{
    LONG summe = 0;
    WORD val;

    while ( (*quelle >= '0' && *quelle <= '9') ||
            (*quelle >= 'A' && *quelle <= 'F') ||
            (*quelle >= 'a' && *quelle <= 'f') )
    {
        if (*quelle <= '9')
            val = (WORD)(*quelle - '0');
        else if (*quelle <= 'F')
            val = (WORD)(*quelle - 'A' + 10);
        else
            val = (WORD)(*quelle - 'a' + 10);

        summe = summe * 16 + val;
        quelle++;
    }

    return summe;
}

int main(void)
{
    printf("%ld\n", xtol((const BYTE *)"1A")); /* 26 */
    printf("%ld\n", xtol((const BYTE *)"2G")); /* 2  (stops at 'G') */
    return 0;
}
