#include <stdio.h>

typedef unsigned char BYTE;
typedef signed short  WORD;

/* 10.2: Basic strcmp (book form)
   - compare byte by byte
   - stop when different OR at '\0'
   - return (*txt1 - *txt2)
*/
WORD my_strcmp_basic(const BYTE *txt1, const BYTE *txt2)
{
    while (*txt1 == *txt2 && *txt1) {
        txt1++;
        txt2++;
    }
    return (WORD)((int)(*txt1) - (int)(*txt2));
}

int main(void)
{
    printf("ABC vs ABC = %d\n", (int)my_strcmp_basic((const BYTE *)"ABC", (const BYTE *)"ABC"));
    printf("ABC vs ABD = %d\n", (int)my_strcmp_basic((const BYTE *)"ABC", (const BYTE *)"ABD"));
    printf("ABD vs ABC = %d\n", (int)my_strcmp_basic((const BYTE *)"ABD", (const BYTE *)"ABC"));
    printf("A   vs a   = %d\n", (int)my_strcmp_basic((const BYTE *)"A",   (const BYTE *)"a"));

    return 0;
}
