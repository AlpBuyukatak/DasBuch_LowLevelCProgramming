/*7.1 Structure Declarations - Page 100
Assign array member using strcpy
*/

#include <stdio.h>
#include <string.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

typedef struct {
    WORD tag;
    BYTE monat[10];
    WORD jahr;
} DATUM;

int main(void) {
    DATUM geboren;

    // Example 3: copy a string into the array member
    strcpy((char*)geboren.monat, "Mai");

    printf("monat=%s\n", geboren.monat);
    return 0;
}
