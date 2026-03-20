#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;

/* 9.1: Singly Linked Lists (contiguous allocation example)
The beginning of a list is identified by a pointer to the first node.
The end of the list is marked by a NULL pointer in the last node.
Several nodes may be allocated using a single malloc call (example case).
*/
typedef struct idat {
    WORD data;
    struct idat *next;
} INT_N;

int main(void) {
    INT_N *first = 0;

    first = (INT_N *)malloc(3 * sizeof(INT_N));
    if (!first) {
        printf("malloc failed\n");
        return 1;
    }

    first[0].data = 11;
    first[1].data = 22;
    first[2].data = 33;

    first[0].next = first + 1;  /* 1st -> 2nd */
    first[1].next = first + 2;  /* 2nd -> 3rd */
    first[2].next = 0;          /* 3rd -> NULL */

    for (INT_N *p = first; p; p = p->next) {
        printf("%u ", p->data);
    }
    printf("\n");

    free(first);
    return 0;
}
