//4.2 Array Address as a Function Argument
// Copying Arrays using Pointers (acopy1 / acopy2) just an example. Examine the 2 methods of copying 
/*
This code copies an integer array in two different ways—once using array indexing 
and once using pointer arithmetic—and prints all results to show that 
both methods produce identical copies.
*/
#include <stdio.h>
// Copy array using indexing
void acopy1(int d[], const int s[], int n)
{
    for(int i = 0; i < n; i++)
        d[i] = s[i];
}

// Copy array using pointers
void acopy2(int *d, const int *s, int n)
{
    while(n--)
        *d++ = *s++;
}

int main()
{
    int src[] = {10, 20, 30, 40, 50};
    int n = sizeof(src) / sizeof(src[0]); // 20 / 4byte = 5 

    int dst1[n];
    int dst2[n];

    acopy1(dst1, src, n);
    acopy2(dst2, src, n);

    printf("Source array : ");
    for(int i = 0; i < n; i++) printf("%d ", src[i]);

    printf("\n Copied (indexing) : ");
    for(int i = 0; i < n; i++) printf("%d ", dst1[i]);

    printf("\n Copied (pointer)  : ");
    for(int i = 0; i < n; i++) printf("%d ", dst2[i]);

    return 0;
}
