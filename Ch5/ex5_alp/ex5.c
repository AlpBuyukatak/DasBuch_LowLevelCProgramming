//5.2 String Arrays - page 81
#include <stdio.h>

int main() {
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int *p = a[1];   // Address of line 2

    printf("%d %d %d\n", p[0], p[1], p[2]);
    return 0;
}
