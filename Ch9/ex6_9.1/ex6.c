#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;

/* 9.1: Deleting Nodes from a Singly Linked List
Deleting a node requires updating the predecessor’s next pointer.
Special cases: deleting the first or the last node.
The deleted node must be freed explicitly.
*/
typedef struct idat {
    WORD data;
    struct idat *next;
} INT_N;

static void append_fast(INT_N **first, INT_N **last, WORD value) {
    INT_N *n = (INT_N *)malloc(sizeof(INT_N));
    if (!n) return;

    n->data = value;
    n->next = 0;

    if (!*first) {
        *first = *last = n;
    } else {
        (*last)->next = n;
        *last = n;
    }
}

static void delete_value(INT_N **first, INT_N **last, WORD value) {
    INT_N *prev = 0;
    INT_N *cur  = *first;

    while (cur && cur->data != value) {
        prev = cur;
        cur  = cur->next;
    }
    if (!cur) return;                /* not found */

    if (prev == 0) {                 /* delete first */
        *first = cur->next;
    } else {
        prev->next = cur->next;
    }

    if (cur->next == 0) {            /* delete last */
        *last = prev;
    }

    free(cur);
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
    INT_N *last  = 0;

    append_fast(&first, &last, 10);
    append_fast(&first, &last, 20);
    append_fast(&first, &last, 30);
    append_fast(&first, &last, 40);

    print_list(first);

    delete_value(&first, &last, 10);   /* delete first */
    print_list(first);

    delete_value(&first, &last, 40);   /* delete last */
    print_list(first);

    delete_value(&first, &last, 30);   /* delete middle */
    print_list(first);

    free_list(first);
    return 0;
}
