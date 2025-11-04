#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint16_t WORD;

/* 
   Calculates element-wise absolute difference between arr1 and arr2.
   - arr1: first array, updated in-place with the smaller of the two values
   - arr2: second array (read-only)
   - n   : number of elements
   Returns:
   - pointer to a new array that holds |arr1[i] - arr2[i]| values
   - the caller must free() the returned array
*/
WORD *int_arr_absdiff(WORD *arr1, const WORD *arr2, size_t n)
{
    // Allocate memory for the new array that will store absolute differences
    WORD *diffs = (WORD *)malloc(n * sizeof(WORD));
    if (!diffs) return NULL; // If allocation fails, return NULL

    for (size_t i = 0; i < n; ++i) {
        // Compute absolute difference safely
        if (arr1[i] > arr2[i])
            diffs[i] = arr1[i] - arr2[i];
        else
            diffs[i] = arr2[i] - arr1[i];

        // Update arr1 with the smaller value between arr1[i] and arr2[i]
        arr1[i] = (arr1[i] < arr2[i]) ? arr1[i] : arr2[i];
    }

    return diffs;  // Return address of the new array
}

/* --- Example usage --- */
int main(void)
{
    WORD arr1[] = {10, 50, 90, 30};
    WORD arr2[] = {20, 10, 40, 80};
    size_t n = sizeof arr1 / sizeof arr1[0];

    WORD *diffs = int_arr_absdiff(arr1, arr2, n);
    if (!diffs) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Smaller values (arr1): ");
    for (size_t i = 0; i < n; ++i) printf("%u ", arr1[i]);

    printf("\nAbsolute differences:  ");
    for (size_t i = 0; i < n; ++i) printf("%u ", diffs[i]);
    printf("\n");

    free(diffs);
    return 0;
}
