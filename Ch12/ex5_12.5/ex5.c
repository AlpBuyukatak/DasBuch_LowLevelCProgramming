/* 12.5: Manual Data Entry (book-aligned minimal)
- Allocate space for one data record (dynamic memory).
- daten_init() fills the record by keyboard input.
- Shows: "data are entered and written into a data record".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31
#define TEL_LEN  13
#define CC_LEN    3

typedef struct {
    char cc[CC_LEN + 1];
    long num;
} PLZ;

typedef struct {
    char vorname[NAME_LEN + 1];
    char nachname[NAME_LEN + 1];
    PLZ  plz;
    char telefon[TEL_LEN + 1];
} PDAT;

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[n-1] = '\0';
}

static void read_line(const char *prompt, char *buf, size_t cap) {
    printf("%s", prompt);
    if (!fgets(buf, (int)cap, stdin)) { buf[0] = '\0'; return; }
    trim_newline(buf);
}

int daten_init(PDAT *d) {
    char in[128];

    read_line("Vorname  : ", in, sizeof(in));
    if (in[0] == '\0') return 0;
    strncpy(d->vorname, in, sizeof(d->vorname)-1);

    read_line("Nachname : ", in, sizeof(in));
    if (in[0] == '\0') return 0;
    strncpy(d->nachname, in, sizeof(d->nachname)-1);

    read_line("PLZ-CC (optional, max 3) : ", in, sizeof(in));
    in[3] = '\0';
    strncpy(d->plz.cc, in, sizeof(d->plz.cc)-1);

    read_line("PLZ number: ", in, sizeof(in));
    d->plz.num = strtol(in, NULL, 10);

    read_line("Telefon  : ", in, sizeof(in));
    strncpy(d->telefon, in, sizeof(d->telefon)-1);

    return 1;
}

int main(void) {
    PDAT *d = (PDAT *)calloc(1, sizeof(PDAT));
    if (!d) {
        puts("No memory space for data.");
        return 1;
    }

    if (!daten_init(d)) {
        puts("Input aborted.");
        free(d);
        return 0;
    }

    puts("\nRecord entered:");
    printf("%s %s, %s-%ld, %s\n",
           d->vorname, d->nachname,
           d->plz.cc, d->plz.num,
           d->telefon);

    free(d);
    return 0;
}
