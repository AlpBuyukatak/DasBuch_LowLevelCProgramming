/*7.1 Structure Declarations - Page 101
typedef DATUM and nested structure PERSON
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

typedef struct {
    WORD lfd_nr;
    BYTE vorname[25];
    BYTE nachname[35];
    BYTE wohnort[35];
    BYTE strasse[35];
    DATUM geboren;
    DATUM heirat;
} PERSON;

int main(void) {
    PERSON klaus;

    // Example 5: fill basic person data
    klaus.lfd_nr = 1;
    strcpy((char*)klaus.vorname, "Klaus");
    strcpy((char*)klaus.nachname, "Schroeder");
    strcpy((char*)klaus.wohnort, "Erlangen");
    strcpy((char*)klaus.strasse, "Hauptstrasse 2");

    // nested structure: born date
    klaus.geboren.tag = 6;
    strcpy((char*)klaus.geboren.monat, "Mai");
    klaus.geboren.jahr = 1950;

    // nested structure: marriage date
    klaus.heirat.tag = 7;
    strcpy((char*)klaus.heirat.monat, "August");
    klaus.heirat.jahr = 1970;

    printf("%s %s (id=%u)\n", klaus.vorname, klaus.nachname, klaus.lfd_nr);
    printf("Born:  %u %s %u\n",
           klaus.geboren.tag, klaus.geboren.monat, klaus.geboren.jahr);
    printf("Marry: %u %s %u\n",
           klaus.heirat.tag, klaus.heirat.monat, klaus.heirat.jahr);

    return 0;
}
