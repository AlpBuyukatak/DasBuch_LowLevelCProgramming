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