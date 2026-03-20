/*
In this example, a complete structure assignment is performed, 
where all members of one structure (including array members) are copied 
to another structure of the same type.
*/

#include <stdio.h>
#include <string.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

typedef struct {
    WORD day;
    BYTE month[10];
    WORD year;
} DATUM;

int main(void) {
    DATUM a, b;

    a.day = 15;
    strcpy(a.month, "Aug");
    a.year = 2025;

    b = a;   // complete structure assignment (all members are copied)

    printf("a: %u %s %u\n", a.day, a.month, a.year);
    printf("b: %u %s %u\n", b.day, b.month, b.year);

    return 0;
}
