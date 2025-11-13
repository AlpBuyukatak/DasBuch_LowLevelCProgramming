#include <stdio.h>
#include <stdlib.h>

/*
  Function: int_arr_div
  ---------------------
   Computes the remainder of element-wise integer division:
       result[i] = arr1[i] % arr2[i]

   Parameters:
       arr1  - pointer to the first integer array (dividends)
       arr2  - pointer to the second integer array (divisors)
       n     - number of elements in both arrays
 
   Return:
       A pointer to a newly allocated array of size n that contains
       all remainder values.
 
       The memory is allocated on the heap using malloc, so the caller
       MUST free() this pointer after use.
 
       If memory allocation fails, the function returns NULL.
 */
int* int_arr_div(const int *arr1, const int *arr2, size_t n)
{
    // Allocate memory on the heap for n integers
    int *remainders = (int*) malloc(n * sizeof(int));
    if (remainders == NULL) {
        // If allocation fails, return NULL to indicate an error
        return NULL;
    }

    // Compute remainders element by element
    for (size_t i = 0; i < n; ++i) {
        if (arr2[i] == 0) {
            // Division by zero is not allowed.
            // Here we choose to store 0 as a convention.
            remainders[i] = 0;
        } else {
            remainders[i] = arr1[i] % arr2[i];
        }
    }

    // Return the address of the heap-allocated array
    return remainders;
}

int main(void)
{
    // Example input arrays
    int arr1[] = {10, 20, 30, 40, 50};   // dividends
    int arr2[] = {3,  4,  5,  0,  7};    // divisors (note: one element is 0)
    size_t n = sizeof(arr1) / sizeof(arr1[0]);

    // Call the function to compute remainders
    int *result = int_arr_div(arr1, arr2, n);
    if (result == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    // Print the results
    printf("Remainders of arr1[i] %% arr2[i]:\n");
    for (size_t i = 0; i < n; ++i) {
        printf("arr1[%zu] = %d, arr2[%zu] = %d -> remainder = %d\n",
               i, arr1[i], i, arr2[i], result[i]);
    }

    // Free the heap-allocated memory
    free(result);

    return 0;
}
