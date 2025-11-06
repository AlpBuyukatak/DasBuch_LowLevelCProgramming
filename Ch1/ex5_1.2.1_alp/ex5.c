//1.2.1 Data Type double
//float and double differences
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