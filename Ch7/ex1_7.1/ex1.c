/*7.1 Structure Declarations - Page 99
Assign scalar members (tag, jahr)
*/

#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

typedef struct {
    WORD tag;
    BYTE monat[10];
    WORD jahr;
} DATUM;

int main(void) {
    DATUM geboren;

    // Example 1: assign scalar members
    geboren.tag  = 6;
    geboren.jahr = 1950;

    // monat not set here; print only what we assigned
    printf("tag=%u, jahr=%u\n", geboren.tag, geboren.jahr);
    return 0;
}
