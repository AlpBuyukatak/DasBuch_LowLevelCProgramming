//3.2 Null Pointer - page 48
// JUST EXAMINE THE CODE
/*
This code checks a NULL pointer, then uses malloc to allocate memory, 
stores a value through the pointer, prints it, and finally frees the allocated memory. 
It demonstrates safe dynamic memory allocation and NULL checking.
*/
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