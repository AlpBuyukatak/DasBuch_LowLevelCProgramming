#include <stdio.h>
#include "data.h"

int main(void) {
    printf("counter = %d, sum = %ld\n", counter, sum);
    accumulate(3);
    accumulate(7);
    printf("counter = %d, sum = %ld\n", counter, sum);
    return 0;
}