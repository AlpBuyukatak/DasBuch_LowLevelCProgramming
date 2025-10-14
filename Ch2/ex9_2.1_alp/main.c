#include <stdio.h>

// declaration (no storage here) easy level
extern int counter;

int main(void) {
    printf("Counter = %d\n", counter);
    counter++;
    printf("Counter after ++ = %d\n", counter);
    return 0;
}