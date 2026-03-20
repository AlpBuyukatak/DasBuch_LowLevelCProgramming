//1.2.1 Data Type double
/*
This code shows the loss of precision in floating-point arithmetic by 
comparing how float and double handle adding 1 to a very large number; 
the float loses the increment (prints 0), while the double keeps it (prints 1).
*/
#include <stdio.h>

int main(void) {
    float  xf = 1e8f;   // 100 million
    double xd = 1e8;

    float  rf = (xf + 1.0f) - xf;
    double rd = (xd + 1.0) - xd;

    printf("float  result: %.0f\n", (double)rf);
    printf("double result: %.0f\n", rd);

    return 0;
}
