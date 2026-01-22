/* ex10_9.c — 10.3: Plausibility principle (stop at first invalid char) */

#include <stdio.h>

typedef unsigned char BYTE;
typedef signed long   LONG;

/* A number ends when a character does not belong to the validity range.
   Here: decimal digits '0'..'9'
*/
LONG atol_plaus(const BYTE *quelle)
{
    LONG summe = 0;

    while (*quelle >= '0' && *quelle <= '9')
        summe = summe * 10 + (*quelle++ - '0');

    return summe;
}

int main(void)
{
    printf("%ld\n", atol_plaus((const BYTE *)"123Z9")); /* prints 123 */
    return 0;
}
