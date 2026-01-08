#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;

/* 9.1: Singly Linked List with First and Last Pointers
An additional pointer to the last node allows constant-time insertion
at the end of the list, avoiding repeated traversal.
*/
typedef struct idat {
    WORD data;
    struct idat *next;
} INT_N;

static void append_fast(INT_N **first, INT_N **last, WORD value) {
    INT_N *new_object = (INT_N *)malloc(sizeof(INT_N));
    if (!new_object) return;

    new_object->data = value;
    new_object->next = 0;

    if (*first == 0) {               /* empty list */
        *first = *last = new_object;
    } else {
        (*last)->next = new_object;
        *last = new_object;
    }
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

    print_list(first);

    free_list(first);
    return 0;
}
