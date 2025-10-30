#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef uint16_t WORD;  // 16-bit element type

/* 1) Copy using indexing */
void acopy1(WORD dest[], const WORD source[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        dest[i] = source[i];
    }
}

/* 2) Copy using pointer arithmetic */
void acopy2(WORD *dest, const WORD *source, size_t size) {
    while (size--) {
        *dest++ = *source++;
    }
}

static void print_array(const char *name, const WORD *a, size_t n) {
    printf("%s = {", name);
    for (size_t i = 0; i < n; ++i) {
        printf("%s%u", (i ? ", " : ""), (unsigned)a[i]);
    }
    printf("}\n");
}

int main(void) {
    WORD xarr[5] = {10, 20, 30, 40, 50};
    WORD yarr[5] = {0};
    WORD zarr[5] = {0};
    size_t n = sizeof xarr / sizeof xarr[0];

    acopy1(yarr, xarr, n);   // copy via indexing
    acopy2(zarr, xarr, n);   // copy via pointers

    print_array("xarr", xarr, n);
    print_array("yarr (acopy1)", yarr, n);
    print_array("zarr (acopy2)", zarr, n);

    return 0;
}
