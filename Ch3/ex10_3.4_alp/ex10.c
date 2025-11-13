// 3.4 Access with Pointers
/*
This code demonstrates how a pointer and a pointer-to-pointer can both 
modify the same variable (x) through single and double dereferencing, 
and finally verifies that pp indeed stores the address of p.
*/
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int x = 10;      // 1) regular variable
    int *p = &x;     // 2) p points to x
    int **pp = &p;   // 3) pp points to p

    // 4) initial reads
    printf("Start:      x=%d, *p=%d, **pp=%d\n", x, *p, **pp);

    // 5) modify x via p (single-level dereference)
    *p = 20;
    printf("After *p=20: x=%d, *p=%d, **pp=%d\n", x, *p, **pp);

    // 6) modify x via pp (double-level dereference)
    **pp = 35;
    printf("After **pp=35: x=%d, *p=%d, **pp=%d\n", x, *p, **pp);

    // 7) address relationship check: pp should equal &p
    printf("pp == &p ? %s\n", (pp == &p) ? "true" : "false");

    return 0;
}