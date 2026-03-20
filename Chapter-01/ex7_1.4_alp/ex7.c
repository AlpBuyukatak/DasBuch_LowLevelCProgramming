//1.4 Type Definition
/*
This code demonstrates three ways to compute a square in C: 
returning the result, printing it directly, or writing it to an output pointer,
and then shows how each approach behaves in expressions.*/
#include <stdio.h>

/* Returns the square of x for option a*/
int square(int x) {
    return x * x;
}

/* Prints the square of x (returns nothing) for option b  */
void square_print(int x) {
    printf("%d^2 = %d\n", x, x * x);
}

/* Writes the square of x into *out (returns nothing) (uses pointer) for option d */
void square_out(int x, int *out) {
    if (out != NULL) {
        *out = x * x;
    }
}

int main(void) {
    /* a) Use the returning function in an expression */
    int sum = square(5) + square(3);   // 25 + 9 = 34
    printf("sum = %d\n", sum);

    /* b) Use the void printing function */
    square_print(5);
    square_print(3);

    /* c) This line would cause a compile error if uncommented,
       because square_print returns void (no value). */
//  int s = square_print(7);   

    /* d) Use the out-parameter version */
    int a2, b2;
    square_out(5, &a2);   // a2 = 25
    square_out(3, &b2);   // b2 = 9
    int sum2 = a2 + b2;
    printf("sum2 = %d\n", sum2);

    return 0;
}