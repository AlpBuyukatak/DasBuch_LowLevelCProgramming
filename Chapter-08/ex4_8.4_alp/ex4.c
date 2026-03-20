#include <stdio.h>
#include <stdlib.h>

/* 8.4: Function free
free releases dynamically allocated memory.
After free, the pointer must not be used.
*/

int main(void) {
    int *p = malloc(4 * sizeof(int));
    if (p == NULL) return 1;

    for (int i = 0; i < 4; i++) {
        p[i] = i * 10;
    }

    free(p);
    p = NULL;   /* avoid dangling pointer */

    if (p == NULL) {
        printf("memory freed safely\n");
    }

    return 0;
}
