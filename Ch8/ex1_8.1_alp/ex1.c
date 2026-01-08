#include <stdio.h>
#include <stdlib.h>

/* 8.1: Function malloc
malloc allocates uninitialized memory on the heap.
The returned pointer must be checked against NULL.
*/

int main(void) {
    int n = 5;
    int *p = malloc(n * sizeof(int));

    if (p == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
