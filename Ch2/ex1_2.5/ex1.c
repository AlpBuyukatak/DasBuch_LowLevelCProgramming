//2.5 Access to Return Values of Functions - page 31
#include <stdio.h>

/* Functions */
int f1() {
    return 10;
}

int f2() {
    return 2;
}

int f3() {
    return 3;
}

int f4(int x) {
    return x + 1;
}

int f5(int y) {
    return y * y;
}

int main(void) {
    int u, v, w;

    /* 1) The return value of f1 is assigned to u */
    u = f1();               // u = 10

    /* 2) The return values of f2 and f3 are multiplied */
    v = f2() * f3();        // v = 2 * 3 = 6

    /* 3) The return value of f4 is passed as an argument to f5 */
    w = f5(f4(4));          // f4(4) = 5 → f5(5) = 25 → w = 25

    /* Print the results */
    printf("u = %d\n", u);
    printf("v = %d\n", v);
    printf("w = %d\n", w);

    return 0;
}