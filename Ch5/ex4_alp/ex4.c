//5.4 Determining the Size of Multidimensional Data Fields - page 82 
#include <stdio.h>

int main() {
    int a[2][3];

    printf("sizeof(a)        = %zu\n", sizeof(a));
    printf("sizeof(a[0])     = %zu\n", sizeof(a[0]));
    printf("sizeof(a[0][0])  = %zu\n", sizeof(a[0][0]));

    // toplam eleman
    size_t total = sizeof(a) / sizeof(a[0][0]);
    printf("Total elements   = %zu\n", total);

    // bir satırdaki eleman
    size_t per_row = sizeof(a[0]) / sizeof(a[0][0]);
    printf("Elements per row = %zu\n", per_row);

    return 0;
}

/* 
For the array a[2][3]:

2 rows × 3 columns = 6 elements

Since int = 4 bytes:

sizeof(a) = 6 × 4 = 24 bytes

sizeof(a[0]) = one row = 3 × 4 = 12 bytes

sizeof(a[0][0]) = a single element = 4 bytes

From this:

24 / 4 = 6 → total number of elements

12 / 4 = 3 → number of elements in one row
*/