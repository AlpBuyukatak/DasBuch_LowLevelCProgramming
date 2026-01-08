#include <stdio.h>
#include <stdlib.h>

/* 8.2: Function calloc
calloc allocates memory and initializes all bytes to zero.
*/

int main(void) {
    int n = 5;
    int *p = calloc(n, sizeof(int));

    if (p == NULL) {
        printf("calloc failed\n");
        return 1;
    }

    /* values are zero-initialized */
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}
