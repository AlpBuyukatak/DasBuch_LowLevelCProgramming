/* ex10_13.c — 10.3.4: Input Conversion (decision rule only) */

#include <stdio.h>

typedef unsigned char BYTE;
typedef signed long   LONG;

/* Assume these functions already exist (taught earlier) */
LONG atol(const BYTE *q) { return 1; }
LONG otol(const BYTE *q) { return 2; }
LONG xtol(const BYTE *q) { return 3; }

/* 10.3.4: convert — book decision rule
   - "0x" or "0X"  -> hexadecimal
   - leading "0"   -> octal
   - otherwise     -> decimal
*/
LONG convert(const BYTE *cf)
{
    if (*cf == '0') {
        if (cf[1] == 'x' || cf[1] == 'X')
            return xtol(cf + 2);
        else
            return otol(cf + 1);
    }
    return atol(cf);
}

int main(void)
{
    printf("%ld\n", convert((const BYTE *)"123"));   /* decimal  -> atol  */
    printf("%ld\n", convert((const BYTE *)"077"));   /* octal    -> otol  */
    printf("%ld\n", convert((const BYTE *)"0x1A"));  /* hex      -> xtol  */
    return 0;
}
