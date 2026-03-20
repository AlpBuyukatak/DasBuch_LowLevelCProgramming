//2.1 Declaration
/*
This project demonstrates how global variables are defined in data.c, declared with extern in data.h, 
and then shared across multiple files; main.c calls accumulate() 
to update the global counter and sum values stored in data.c.
*/
#include <stdio.h>
#include "data.h"

int main(void) {
    printf("counter = %d, sum = %ld\n", counter, sum);
    accumulate(3);
    accumulate(7);
    printf("counter = %d, sum = %ld\n", counter, sum);
    return 0;
}