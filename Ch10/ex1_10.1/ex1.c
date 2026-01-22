#include <stdio.h>

/* 10.1.1: const qualifier with pointers
   - const char *p  : data is read-only
   - char * const p : pointer is read-only
*/

int main(void)
{
    const char *p1 = "HELLO";   /* data const */
    /* p1[0] = 'X'; */          /* illegal */

    char buf[] = "HELLO";
    char * const p2 = buf;      /* pointer const */
    p2[0] = 'X';                /* legal */

    printf("buf = %s\n", buf);  /* XELLO */
    return 0;
}
