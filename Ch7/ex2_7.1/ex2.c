/*7.1 Structure Declarations - Page 99
Assign array member manually (monat[ ])
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

    // Example 2: write the string "Mai" manually and terminate it
    geboren.monat[0] = 'M';
    geboren.monat[1] = 'a';
    geboren.monat[2] = 'i';
    geboren.monat[3] = '\0';

    printf("monat=%s\n", geboren.monat);
    return 0;
}
