#include <stdio.h>
#include <string.h>

typedef unsigned short WORD;
typedef unsigned char  BYTE;

typedef struct {
    WORD day;
    BYTE month[10];
    WORD year;
} DATUM;

/* The function receives a complete structure */
void printDate(DATUM d) {
    printf("%u %s %u\n", d.day, d.month, d.year);
}

/* The function returns a complete structure */
DATUM nextYear(DATUM d) {
    d.year = d.year + 1;
    return d;
}

int main(void) {
    DATUM today, tomorrow;

    today.day = 6;
    strcpy(today.month, "May");
    today.year = 1950;

    printDate(today);          // structure passed as argument
    tomorrow = nextYear(today); // structure returned from function

    printDate(tomorrow);
    return 0;
}
