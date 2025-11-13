// 3.1 Pointer to void
/*This code uses a function that takes a void* pointer plus a type flag to 
decide whether to print the pointed value as an int or a float. 
It demonstrates how generic functions can handle multiple data types using casting.
*/
#include <stdio.h>

void printValue(void *data, char type) {
    if (type == 'i')
        printf("%d\n", *(int *)data);
    else if (type == 'f')
        printf("%.2f\n", *(float *)data);
}

int main() {
    int a = 42;
    float b = 3.14;

    printValue(&a, 'i');  // print int  
    printValue(&b, 'f');  // print float
    
}