
//3.0 Pointer
// JUST EXAMINE THE CODE
#include <stdio.h>
typedef unsigned int WORD;

int main() {
    WORD x = 10;
    WORD y = 20;

    WORD *p;     // p -> pointer to WORD
    WORD *q;     // q -> pointer to WORD

    p = &x;                   // p stores the address of x (*p shows the value of the specified adress)
    q = (WORD *)0x1000;       // q is assigned the address 0x1000 (example)

    printf("x = %u\n", x);
    printf("*p = %u\n", *p);  // *p = the value of x
    printf("address stored in p = %p\n", p);
    printf("address stored in q = %p\n", q);

    // pointer-to-pointer example
    WORD **pp = &p;
    printf("**pp = %u\n", **pp); // ***ppp = **pp = *p = the value of x 

    return 0;
}

//NOTE: WORD = unsigned int