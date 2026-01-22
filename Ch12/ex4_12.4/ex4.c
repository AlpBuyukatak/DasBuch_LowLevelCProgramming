/* 12.4: Displaying data – function show (book-aligned minimal)
- show() prints ONE record in a formatted way.
- It receives a pointer to the data record and only outputs.
*/

#include <stdio.h>
#include <string.h>

#define NAME_LEN 31
#define TEL_LEN  13
#define CC_LEN    3

typedef struct {
    char cc[CC_LEN + 1];   /* optional country code, may be "" */
    long num;              /* numeric part */
} PLZ;

typedef struct {
    char vorname[NAME_LEN + 1];
    char nachname[NAME_LEN + 1];
    PLZ  plz;
    char telefon[TEL_LEN + 1];
} PDAT;

void show(const PDAT *p) {
    printf("Vorname : %s\n", p->vorname);
    printf("Nachname: %s\n", p->nachname);

    if (p->plz.cc[0] != '\0') printf("PLZ     : %s-%ld\n", p->plz.cc, p->plz.num);
    else                     printf("PLZ     : %ld\n", p->plz.num);

    printf("Telefon : %s\n", p->telefon);
}

int main(void) {
    PDAT x;
    memset(&x, 0, sizeof(x));

    strcpy(x.vorname,  "Max");
    strcpy(x.nachname, "Mustermann");
    strcpy(x.plz.cc,   "DE");
    x.plz.num = 91054;
    strcpy(x.telefon,  "09131-1234567");

    show(&x);
    return 0;
}
