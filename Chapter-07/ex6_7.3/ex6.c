/*7.3 Structure Declarations - Page 103
Function receives DATUM and returns DATUM
*/

#include <stdio.h>
#include <string.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

typedef struct {
    WORD day;
    BYTE month[10];
    WORD year;
} DATUM;

/* Example: function takes a DATUM argument and returns a DATUM value */
DATUM f(DATUM x) {
    /* Simple demo: return a modified copy */
    x.year = (WORD)(x.year + 1);
    return x;
}

int main(void) {
    DATUM x, y;

    x.day = 6;
    strcpy((char*)x.month, "May");
    x.year = 1950;

    y = f(x);   /* Function call exactly like the book: y = f(x); */

    printf("x: %u %s %u\n", x.day, x.month, x.year);
    printf("y: %u %s %u\n", y.day, y.month, y.year);

    return 0;
}
