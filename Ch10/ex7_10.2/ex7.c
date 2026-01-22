#include <stdio.h>

typedef unsigned char BYTE;

/* 10.2: Demonstration of side-effect risk with && and pointer increments
   - shows why putting txt1++ inside the while condition is error-prone
*/

int main(void)
{
    const BYTE s1[] = "A";
    const BYTE s2[] = "B";

    const BYTE *t1 = s1;
    const BYTE *t2 = s2;

    /* Risky-style condition (DO NOT use as a recommended strcmp):
       If the first part of && becomes false, the second part is not evaluated.
       Therefore, an increment placed in the second part might not happen.
    */
    while ( (*t1 == *t2) && (*t1++ != 0) ) {
        t2++;
    }

    /* After the loop: print where pointers ended up */
    printf("s1 = \"%s\", s2 = \"%s\"\n", (const char*)s1, (const char*)s2);
    printf("t1 points to: '%c' (offset %ld)\n", *t1 ? *t1 : '0', (long)(t1 - s1));
    printf("t2 points to: '%c' (offset %ld)\n", *t2 ? *t2 : '0', (long)(t2 - s2));

    return 0;
}
