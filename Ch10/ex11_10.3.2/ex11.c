/* ex10_11.c — 10.3.2: otol (octal conversion) */

#include <stdio.h>

typedef unsigned char BYTE;
typedef signed long   LONG;

/* 10.3.2: Converting characters into an octal number — otol
   validity: '0'..'7'
   sum = sum*8 + digit
*/
LONG otol(register const BYTE *quelle)
{
    LONG summe = 0;

    while (*quelle >= '0' && *quelle <= '7')
        summe = summe * 8 + (*quelle++ - '0');

    return summe;
}

int main(void)
{
    printf("%ld\n", otol((const BYTE *)"17"));   /* 15 */
    printf("%ld\n", otol((const BYTE *)"128"));  /* 10 (stops at '8') */
    return 0;
}
