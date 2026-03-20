//3.1 Pointer to void 
// JUST EXAMINE THE CODE
/* This code stores the addresses of different variable types in a void* pointer and 
then casts it to the correct type to print each value. It demonstrates how void* 
can point to any data type.
*/
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