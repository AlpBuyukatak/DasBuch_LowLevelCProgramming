#include <stdio.h>
#include <stdlib.h>  // for malloc() and free()

int main() {
    // Allocate memory for an array of 100 integers
    int *p = malloc(100 * sizeof(int));

    // Check if memory allocation was successful
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit the program with error code
    }

    // Assign values to the first few elements
    p[0] = 10;
    p[1] = 20;
    p[2] = 30;

    // Print the assigned values to verify
    printf("First three values: %d, %d, %d\n", p[0], p[1], p[2]);

    // Release the allocated memory back to the system
    free(p);

    return 0;  // Successful program termination
}

/*
The operating system will allocate memory for an array of 100 int elements.

Perform this operation using the malloc() function, assign a value to the first element of the array, and release the memory when the operation is complete.
(Also, show that malloc()'s void * return eliminates the need for casts.)

*/