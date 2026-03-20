/*7.1 Structure Declarations - Page 101
Use a struct tag (struct datum) and declare variables
*/

#include <stdio.h>
#include <string.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

struct datum {
    WORD tag;
    BYTE monat[10];
    WORD jahr;
};

int main(void) {
    struct datum geboren, heirat;

    // Example 4: declare variables of "struct datum"
    geboren.tag = 6;
    strcpy((char*)geboren.monat, "Mai");
    geboren.jahr = 1950;

    heirat.tag = 7;
    strcpy((char*)heirat.monat, "Aug");
    heirat.jahr = 1970;

    printf("Born:  %u %s %u\n", geboren.tag, geboren.monat, geboren.jahr);
    printf("Marry: %u %s %u\n", heirat.tag, heirat.monat, heirat.jahr);
    return 0;
}

