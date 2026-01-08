#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;

/* 9.1: Appending Nodes to a Singly Linked List (searching last node)
To insert a node at the end, the list must be traversed
until the last node is found. This is linear in time.
*/
typedef struct idat {
    WORD data;
    struct idat *next;
} INT_N;

static void append(INT_N **first, WORD value) {
    INT_N *new_object = (INT_N *)malloc(sizeof(INT_N));
    if (!new_object) return;

    new_object->data = value;
    new_object->next = 0;

    if (*first == 0) {               /* list empty */
        *first = new_object;
        return;
    }

    INT_N *p;
    for (p = *first; p->next; p = p->next) {
        /* search last */
    }
    p->next = new_object;
}

static void print_list(const INT_N *first) {
    for (const INT_N *p = first; p; p = p->next) {
        printf("%u ", p->data);
    }
    printf("\n");
}

static void free_list(INT_N *first) {
    while (first) {
        INT_N *next = first->next;
        free(first);
        first = next;
    }
}

int main(void) {
    INT_N *first = 0;

    append(&first, 10);
    append(&first, 20);
    append(&first, 30);

    print_list(first);

    free_list(first);
    return 0;
}
