//2.6 Explicit Type Conversion - page 32
#include <stdio.h>

/* f1 returns an int */
int f1(void) {
    return 42;
}

/* f2 expects a double */
void f2(double x) {
    printf("Value as double = %.2f\n", x);
}

int main(void) {
    /* Cast the return value of f1 to double before passing to f2 */
    f2((double) f1());

    return 0;
}