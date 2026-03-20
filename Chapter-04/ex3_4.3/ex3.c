//4.3 Array Address as Return Value of a Function
/*
This code divides each element of arr1 by the corresponding element of arr2, storing the 
quotient back into arr1 and returning a newly allocated array that contains 
all remainders, while safely handling division by zero.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint16_t WORD; // defines WORD as 16-bit

/*  
   arr1 → contains the dividends  
   arr2 → contains the divisors  
   n    → number of elements  
   Returns: A pointer to a new array (allocated with malloc) that stores the remainders.    
*/
WORD *int_arr_div(WORD *arr1, const WORD *arr2, size_t n)
{
    // Allocate memory dynamically for remainders
    WORD *rems = (WORD *)malloc(n * sizeof(WORD));
    if (!rems) return NULL;  // If allocation fails, return NULL

    // Loop through all array elements
    for (size_t i = 0; i < n; ++i) {
        if (arr2[i] == 0) {       // Protect against division by zero
            rems[i]  = arr1[i];   // If divisor is 0, remainder = dividend
            arr1[i]  = 0;         // Define quotient as 0 (just a safe fallback)
        } else {
            rems[i]  = (WORD)(arr1[i] % arr2[i]);   // store remainder kalan 
            arr1[i]  = (WORD)(arr1[i] / arr2[i]);   // update arr1 with quotient bölüm
        }
    }

    return rems;  // Return the pointer to the remainder array
}

/* I randomly gave values to arr1 and arr2 */
int main(void)
{
    WORD arr1[] = {10, 20, 30, 40};
    WORD arr2[] = {3,  5,  7,  0};
    size_t n = sizeof arr1 / sizeof arr1[0];

    WORD *rema = int_arr_div(arr1, arr2, n);
    if (!rema) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // fail so returns 1
    }

    printf("Quotients (arr1): ");
    for (size_t i = 0; i < n; ++i) printf("%u ", arr1[i]);

    printf("\nRemainders (return value): ");
    for (size_t i = 0; i < n; ++i) printf("%u ", rema[i]);
    printf("\n");

    free(rema);  // Always release malloc'ed memory when done
    return 0;
}
