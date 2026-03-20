/*
This example demonstrates how multiple structure objects are stored in an array 
and how individual structure members are accessed using array indexing and the . operator.
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
    DATUM holidays[3];  // array of structures
        
/*In C, you cannot assign values ​​to arrays using `=" 
because an array is a fixed block of memory, 
not an address; to assign a string, its contents are copied using `strcpy`.
*/
    // element 0
    holidays[0].day = 1;
    strcpy(holidays[0].month, "Jan");
    holidays[0].year = 2026;

    // element 1
    holidays[1].day = 23;
    strcpy(holidays[1].month, "Apr");
    holidays[1].year = 2026;

    // element 2
    holidays[2].day = 1;
    strcpy(holidays[2].month, "May");
    holidays[2].year = 2026;

    // iterate over the array and print each structure
    for (int i = 0; i < 3; i++) {
        printf("%u %s %u\n",
               holidays[i].day,
               holidays[i].month,
               holidays[i].year);
    }

    return 0;
}
