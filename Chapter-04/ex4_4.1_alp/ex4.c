//4.1 Pointer to an Array
/*
This code shows that arrays and pointers can access the same elements: arr[i], p[i], and *(p + i) 
all refer to the same values, demonstrating that pointer arithmetic and array indexing 
are equivalent for accessing array elements.
*/
#include <stdio.h>

int main(void) {
    int arr[3] = {10, 20, 30};
    int *p = arr;  // p points the arr[0]

    // access with an Array 
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);

    // access with a Pointer (indexing)
    printf("p[0]   = %d\n", p[0]);
    printf("p[1]   = %d\n", p[1]);

    // access with a Pointer (dereference + offset)
    printf("*(p+0) = %d\n", *(p+0));   // printing the result of *p
    printf("*(p+1) = %d\n", *(p+1));   // and printing this => *p + 1 , throws a different result 

    return 0;
}