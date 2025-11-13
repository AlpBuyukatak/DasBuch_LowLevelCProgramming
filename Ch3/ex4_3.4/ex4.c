//3.4 Access with Pointers - page 51
/*
The operating system will allocate memory for an array of 100 int elements.
Perform this operation using the malloc() function, assign a value to the first element of the array, 
and release the memory when the operation is complete.
(Also, show that malloc()'s void * return eliminates the need for casts.)
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(100 * sizeof(int));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory successfully allocated at address: %p\n", (void*)p);

    // print addresses of a few elements
    for (int i = 0; i < 5; i++)
        printf("&p[%d] = %p\n", i, (void*)&p[i]);

    free(p);
    return 0;
}