// 5.5 Pointer Addressing of Multidimensional Data Fields - page 85
#include <stdio.h>

int main() {

    int a[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int (*p)[3] = a;   // p: 3-element sequential pointer

    printf("%d\n", p[1][2]);   // 6

    return 0;
}
