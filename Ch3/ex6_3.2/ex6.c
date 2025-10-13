
//3.2 Null Pointer
// JUST EXAMINE THE CODE

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;   // there s no valid address for now
    //its possible to use this function anyway: int *p = 0; 

    if (!p)
        printf("Pointer is NULL (no address assigned)\n");
    else
        printf("Pointer has a valid address\n");

    // Allocate in the memory:
    p = malloc(sizeof(int));  // if the malloc fails, NULL returns
    if (!p)
        printf("Memory allocation failed!\n");
    else {
        *p = 42;
        printf("Value = %d\n", *p);
        free(p);
    }
}