#include <stdio.h>

typedef unsigned short WORD;

/* 9: Linked Lists
Each list element (node) contains data and a pointer to another node.
Nodes are linked via pointers (not necessarily contiguous in memory).
*/
typedef struct idat {
    WORD data;
    struct idat *next;
} INT_N;

int main(void) {
    INT_N a = { 10, NULL };
    INT_N b = { 20, NULL };

    a.next = &b;  /* link a -> b */

    printf("a.data = %u\n", a.data);
    printf("b.data = %u\n", a.next->data);
    return 0;
}
