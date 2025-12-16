/*In this example, a structure type is defined using typedef, a structure variable is created, 
and its members are accessed and assigned using the . operator.
*/

#include <stdio.h>
#include <string.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

/* 7.1: Structure definition and basic usage */
typedef struct {
    WORD day;          // day of the month
    BYTE month[10];    // month name (string)
    WORD year;         // year
} DATUM;

int main(void) {
    DATUM born;                 // structure variable

    born.day = 6;               // access structure member using '.'
    strcpy(born.month, "May");  // copy string into array member
    born.year = 1950;

    printf("%u %s %u\n", born.day, born.month, born.year);
    return 0;
}
