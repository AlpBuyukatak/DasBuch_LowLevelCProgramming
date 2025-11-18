// 5.1 Two-Dimensional Data Arrays - page 75 - easy 
#include <stdio.h>

int main() {
    int a[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    printf("%d\n", a[1][2]);
    return 0;
}



/*

a[2][3]  → row 2, column 3

row 0:  [ a[0][0]  a[0][1]  a[0][2] ]
row 1:  [ a[1][0]  a[1][1]  a[1][2] ]

*/