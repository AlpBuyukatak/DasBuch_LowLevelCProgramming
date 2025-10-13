//3.1 Pointer to void
// JUST EXAMINE THE CODE

#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;
    char c = 'A';

    void *ptr;  // hold the each type of addresses

    ptr = &x;
    printf("%d\n", *(int *)ptr);   // print as int

    ptr = &y;
    printf("%.2f\n", *(float *)ptr);  // print as float

    ptr = &c;
    printf("%c\n", *(char *)ptr);  // print as char
}
