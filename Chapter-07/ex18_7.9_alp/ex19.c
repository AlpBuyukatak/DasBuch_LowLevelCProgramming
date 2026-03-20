/* 7.9: Variants, Unions (book-aligned example)
A union allows different components to share the same memory area.
Only one member of the union is valid at a time.
The size of a union is determined by its largest member.
Unions are used to interpret the same data in different ways.
*/

#include <stdio.h>

union DATA {
    int   i;
    char  c[4];
};

int main(void) { 
    union DATA d;

    d.i = 0x41424344;   // write as int
    printf("%c %c %c %c\n", d.c[0], d.c[1], d.c[2], d.c[3]);

    return 0;
}
