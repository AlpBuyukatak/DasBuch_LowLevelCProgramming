/* 12.7: Deleting the list – clear (book-aligned minimal)
- Nodes are dynamically allocated.
- Data is also dynamically allocated.
- clear_all() frees ALL nodes and their data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
} PDAT;

typedef struct NODE {
    struct NODE *next;
    struct NODE *prev;
    void *data;            /* points to PDAT */
    int  data_is_malloc;   /* whether data must be freed */
} NODE, *PNODE;

/* create a 1-node circular list */
static PNODE make_one(const char *name) {
    PNODE n = (PNODE)malloc(sizeof(NODE));
    if (!n) return NULL;

    n->data = malloc(sizeof(PDAT));
    if (!n->data) { free(n); return NULL; }

    n->data_is_malloc = 1;
    memset(n->data, 0, sizeof(PDAT));
    strncpy(((PDAT*)n->data)->name, name, 31);

    n->next = n;
    n->prev = n;
    return n;
}

/* insert new node after 'list' */
static PNODE insert_after(PNODE list, const char *name) {
    PNODE n = make_one(name);
    if (!n) return list;

    n->next = list->next;
    n->prev = list;
    list->next->prev = n;
    list->next = n;
    return list;
}

static void clear_all(PNODE list) {
    if (!list) return;

    PNODE p = list->next;
    while (p != list) {
        PNODE next = p->next;
        if (p->data_is_malloc && p->data) free(p->data);
        free(p);
        p = next;
    }
    if (list->data_is_malloc && list->data) free(list->data);
    free(list);
}

int main(void) {
    PNODE list = make_one("Max");
    list = insert_after(list, "Anna");
    list = insert_after(list, "John");

    puts("List created. Now deleting...");
    clear_all(list);
    puts("Deleted.");

    return 0;
}
