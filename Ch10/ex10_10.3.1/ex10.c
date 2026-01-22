/* ex10_10.c — 10.3.1: atol (decimal conversion) */

#include <stdio.h>

typedef unsigned char BYTE;
typedef signed long   LONG;

/* 10.3.1: Converting characters into a decimal number — atol
   validity: '0'..'9'
   sum = sum*10 + digit
*/
LONG atol(register const BYTE *quelle)
{
    LONG summe = 0;

    while (*quelle >= '0' && *quelle <= '9')
        summe = summe * 10 + (*quelle++ - '0');

    return summe;
}

int main(void)
{
    printf("%ld\n", atol((const BYTE *)"123"));   /* 123 */
    printf("%ld\n", atol((const BYTE *)"12AB"));  /* 12  */
    return 0;
}
