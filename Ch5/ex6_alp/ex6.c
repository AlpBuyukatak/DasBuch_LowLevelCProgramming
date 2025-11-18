//5.3 n-Dimensional Data Fields - page 81-82
#include <stdio.h>

int main() {
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int *p = &a[0][0];   // going through the whole series like 1D 
    for (int i = 0; i < 6; i++)
        printf("%d ", *(p+i));

    return 0;
}
/*
Because multidimensional arrays are stored in a single row in memory:

&a[0][0] points to the first element.

*(p+i) reads all elements sequentially:

1 → 2 → 3 → 4 → 5 → 6

*/