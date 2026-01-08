#include <stdio.h>
#include <stdlib.h>

/* 8.3: Function realloc
realloc changes the size of an allocated memory block.
It may return a new pointer.
*/

int main(void) {
    int *p = malloc(3 * sizeof(int));
    if (p == NULL) return 1;

    for (int i = 0; i < 3; i++) {
        p[i] = i + 1;
    }

    int *tmp = realloc(p, 6 * sizeof(int));
    if (tmp == NULL) {
        free(p);
        return 1;
    }
    p = tmp;

    for (int i = 3; i < 6; i++) {
        p[i] = i + 1;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
