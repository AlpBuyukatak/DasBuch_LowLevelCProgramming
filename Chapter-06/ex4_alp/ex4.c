#include <stdio.h>

int main(void) {
    /*
        WRONG:
        int *p[] = { {1,2,3}, {4,5,6} };
        Because {1,2,3} is NOT an address. It is an array initializer.
    */

    int a[] = {1,2,3};
    int b[] = {4,5,6};

    int *p[] = {a, b};  // correct: storing ADDRESSES

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            printf("p[%d][%d] = %d\n", i, j, p[i][j]);

    return 0;
}
