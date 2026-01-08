#include <stdio.h>
#include <stdlib.h>

/* 9.2: Doubly Linked Lists (Ring Structure)
Each node contains pointers to both its predecessor and successor.
In a ring list, the last node points back to the first node.
This structure simplifies insertion and deletion at arbitrary positions.
*/
typedef struct node {
    void *data;
    struct node *prev;
    struct node *next;
} DLL_NODE;

/* 9.2: Inserting and Deleting Nodes in a Doubly Linked Ring List
Insertion and deletion update both next and prev pointers.
The list is accessed through a rotating pointer that may refer
to any node in the ring.
*/

/* insert new node AFTER p; return pointer to inserted node (or first node if list empty) */
static DLL_NODE *insert_after(DLL_NODE *p, void *data) {
    DLL_NODE *n = (DLL_NODE *)malloc(sizeof(DLL_NODE));
    if (!n) return 0;

    n->data = data;

    if (p == 0) {            /* empty ring */
        n->prev = n;
        n->next = n;
        return n;
    }

    n->prev = p;
    n->next = p->next;
    p->next->prev = n;
    p->next = n;
    return n;
}

/* delete node p; return next node as new handle, or 0 if list becomes empty */
static DLL_NODE *delete_node(DLL_NODE *p) {
    if (p == 0) return 0;

    if (p->next == p) {      /* single node */
        free(p);
        return 0;
    }

    DLL_NODE *save = p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return save;
}

static void print_ring(DLL_NODE *p) {
    if (!p) {
        printf("(empty)\n");
        return;
    }

    DLL_NODE *start = p;
    do {
        printf("%d ", *(int *)p->data);
        p = p->next;
    } while (p != start);
    printf("\n");
}

static void free_ring(DLL_NODE *p) {
    if (!p) return;

    DLL_NODE *start = p;
    p = p->next;

    while (p != start) {
        DLL_NODE *next = p->next;
        free(p);
        p = next;
    }
    free(start);
}

int main(void) {
    int values[] = { 10, 20, 30, 40 };

    DLL_NODE *dll_ptr = 0;

    dll_ptr = insert_after(dll_ptr, &values[0]);
    insert_after(dll_ptr, &values[1]);
    insert_after(dll_ptr, &values[2]);
    insert_after(dll_ptr, &values[3]);

    print_ring(dll_ptr);

    dll_ptr = delete_node(dll_ptr);
    print_ring(dll_ptr);

    dll_ptr = delete_node(dll_ptr);
    print_ring(dll_ptr);

    free_ring(dll_ptr);
    return 0;
}
