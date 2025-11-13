//2.1 Declaration
/*
This program shows how a global variable is defined in one file (data.c, which allocates storage) 
and declared using extern in another file (main.c), allowing both files to share 
and modify the same global variable counter.
*/
#include <stdio.h>

// declaration (no storage here) easy level
extern int counter;

int main(void) {
    printf("Counter = %d\n", counter);
    counter++;
    printf("Counter after ++ = %d\n", counter);
    return 0;
}
