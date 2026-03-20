/* 7.6: Addresses of structures (book-aligned example) 
When taking addresses of structure components, remember that the structure operator 
has higher priority than the address operator.*/

#include <stdio.h>

typedef struct {
    int tag;
    int year;
} DATE;

int main(void) {
    DATE today;

    today.tag  = 6;
    today.year = 1950;

    /* Address of the entire structure */
    printf("Address of structure today: %p\n", (void *)&today);

    /* WRONG: structure operator has higher priority than '&' */
    /* &today.tag   // this does NOT mean (&today).tag */

    /* CORRECT: take the address first, then access the component */
    printf("Address of tag: %p\n", (void *)&((today).tag));

    return 0;
}
