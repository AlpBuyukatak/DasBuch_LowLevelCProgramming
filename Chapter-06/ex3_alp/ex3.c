#include <stdio.h>

int main(void) {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};

    /* Pointer field: stores addresses, not data */
    int *p[2] = {arr1, arr2};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("p[%d][%d] = %d\n", i, j, p[i][j]);
        }
    }

    /*
      NOTE:
      Pointer fields only store ADDRESSES.
      The actual integers are stored inside arr1 and arr2,
      not inside p[].
    */

    return 0;
}
