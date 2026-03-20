#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;

/* 9.1: Inserting at the Beginning of a Singly Linked List
Insertion at the beginning is efficient because the first node
is directly accessible via the list pointer (no traversal required).
*/
typedef struct idat {
    WORD data;
    struct idat *next;
} INT_N;

static void insert_first(INT_N **first, WORD value) {
    INT_N *new_object = (INT_N *)malloc(sizeof(INT_N));
    if (!new_object) return;

    new_object->data = value;
    new_object->next = *first;
    *first = new_object;
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

    insert_first(&first, 30);
    insert_first(&first, 20);
    insert_first(&first, 10);

    print_list(first);

    free_list(first);
    return 0;
}
