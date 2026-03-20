/* 7.7: Pointers to structures (book-aligned note)
When using pointers to structures, remember that the structure member operator
has higher priority than the dereference and address operators.
Therefore, parentheses are required in expressions like (*ptr).member,
and the shorthand operator -> can be used instead.
*/

#include <stdio.h>

typedef struct {
    int value;
} ITEM;

int main(void) {
    ITEM a[2] = { {10}, {20} };
    ITEM *ptr;

    // pointer to structure
    ptr = &a[0];

    // 1) explicit form (parentheses are required)
    printf("%d\n", (*ptr).value);

    // 2) shorthand operator ->
    printf("%d\n", ptr->value);

    // 3) pointer arithmetic on structure array
    ptr++;                  // moves by sizeof(ITEM)
    printf("%d\n", ptr->value);   // now a[1]

    // 4) operator precedence example
    // &a[0].value  is NOT the same as  &(a[0]).value
    int *p = &(a[0].value);
    printf("%d\n", *p);

    return 0;
}
// NOTE: "  ptr->value  " EQUALS TO "  (*ptr).value  "