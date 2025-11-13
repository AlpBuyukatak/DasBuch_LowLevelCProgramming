//2.6 Explicit Type Conversion - page 32
/*
This code calls f1() to get an int, casts that return value to double, 
and passes it to f2(), which prints it in double format.
*/

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