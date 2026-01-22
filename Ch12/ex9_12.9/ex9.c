/* 12.9: Sorting the List (book-aligned minimal concept)
Key idea:
- Do NOT swap nodes or move list links.
- Instead, collect PDAT* pointers into an array, sort that array,
  then write the pointers back into the nodes in sorted order.
This demonstrates the core method without file I/O or menu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nachname[32];
    char vorname[32];
} PDAT;

typedef struct NODE {
    struct NODE *next;
    struct NODE *prev;
    void *data; /* PDAT* */
} NODE, *PNODE;

static PNODE make_node(PDAT *d) {
    PNODE n = (PNODE)malloc(sizeof(NODE));
    if (!n) return NULL;
    n->data = d;
    n->next = n->prev = n;
    return n;
}

static PNODE insert_after(PNODE list, PDAT *d) {
    PNODE n = make_node(d);
    if (!n) return list;

    if (!list) return n;

    n->next = list->next;
    n->prev = list;
    list->next->prev = n;
    list->next = n;
    return list;
}

static int list_count(PNODE list) {
    if (!list) return 0;
    int c = 0;
    PNODE p = list;
    do { c++; p = p->next; } while (p != list);
    return c;
}

/* compare: lastname, then firstname */
static int pdat_ptr_cmp(const void *a, const void *b) {
    const PDAT *pa = *(const PDAT * const *)a;
    const PDAT *pb = *(const PDAT * const *)b;
    int r = strcmp(pa->nachname, pb->nachname);
    if (r != 0) return r;
    return strcmp(pa->vorname, pb->vorname);
}

/* core 12.9 idea: sort by pointer array */
static void sort_list_by_data_pointers(PNODE list) {
    int n = list_count(list);
    if (n <= 1) return;

    /* 1) collect PDAT* pointers */
    PDAT **arr = (PDAT **)malloc((size_t)n * sizeof(PDAT *));
    if (!arr) return;

    PNODE p = list;
    for (int i=0; i<n; i++) {
        arr[i] = (PDAT *)p->data;
        p = p->next;
    }

    /* 2) sort pointer array */
    qsort(arr, (size_t)n, sizeof(PDAT *), pdat_ptr_cmp);

    /* 3) write sorted pointers back to nodes */
    p = list;
    for (int i=0; i<n; i++) {
        p->data = arr[i];
        p = p->next;
    }

    free(arr);
}

static void print_list(PNODE list) {
    if (!list) { puts("(empty)"); return; }
    PNODE p = list;
    do {
        PDAT *d = (PDAT *)p->data;
        printf("%s, %s\n", d->nachname, d->vorname);
        p = p->next;
    } while (p != list);
}

int main(void) {
    /* create 3 PDAT records */
    PDAT *a = (PDAT *)calloc(1, sizeof(PDAT));
    PDAT *b = (PDAT *)calloc(1, sizeof(PDAT));
    PDAT *c = (PDAT *)calloc(1, sizeof(PDAT));

    strcpy(a->nachname, "Zimmer"); strcpy(a->vorname, "Anna");
    strcpy(b->nachname, "Adams");  strcpy(b->vorname, "John");
    strcpy(c->nachname, "Adams");  strcpy(c->vorname, "Ben");

    PNODE list = NULL;
    list = insert_after(list, a);
    list = insert_after(list, b);
    list = insert_after(list, c);

    puts("Before sort:");
    print_list(list);

    sort_list_by_data_pointers(list);

    puts("\nAfter sort:");
    print_list(list);

    /* minimal cleanup */
    free(a); free(b); free(c);
    /* (nodes not freed for brevity; chapter focus is sorting method) */
    return 0;
}
