//3.5.1 Addition/Subtraction of an int Value
/*
This code shows the difference between adding to the value (*p + 1) and 
moving the pointer to the next element *(p + 1) when accessing array elements through a pointer.
*/
#include <stdio.h>

int main(void) {
    int numbers[3] = {10, 20, 30};
    int *p = numbers;   // p points to the first element (10)

    int a = *p + 1;     // reads 10, adds 1 → result = 11
    int b = *(p + 1);   // moves to next int (20), reads it → result = 20

    printf("*p + 1   = %d\n", a);
    printf("*(p + 1) = %d\n", b);

    return 0;
}