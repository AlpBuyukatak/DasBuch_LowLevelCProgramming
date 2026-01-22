/* 12.2: Definition of Data Types and Constants (book-aligned minimal example)
Defines the core record data types and constants used in the address database.
Key ideas:
- Fixed maximum lengths for text fields
- Postal code can include optional 3-letter country code + numeric part
- Data record type resembles the earlier PERSON structure but adapted
This code defines ONLY types + a small init helper.
*/

#include <stdio.h>
#include <string.h>

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  ULONG;

/* Maximum lengths (kept minimal but aligned with idea) */
#define NAME_LEN     31
#define STREET_LEN   41
#define TEL_LEN      13   /* as stated (example: 13 characters) */
#define CC_LEN        3   /* optional country code length */
#define INPUT_LEN    81   /* shared input buffer idea */

/* Postal code: optional 3-letter country code + numeric part */
typedef struct {
    char cc[CC_LEN + 1];  /* e.g., "DE", "USA" (can be empty string) */
    long num;             /* numeric part (range can exceed int) */
} POSTCODE;

/* Core data record (minimal set; extend later in 12.x) */
typedef struct {
    char     name[NAME_LEN + 1];
    char     street[STREET_LEN + 1];
    POSTCODE plz;
    char     tel[TEL_LEN + 1];
} PDAT;

static void pdat_init(PDAT *p) {
    /* deterministic initialization */
    memset(p, 0, sizeof(*p));
    /* optional defaults can be placed here */
}

static void pdat_print(const PDAT *p) {
    printf("Name  : %s\n", p->name);
    printf("Street: %s\n", p->street);
    if (p->plz.cc[0] != '\0')
        printf("PLZ   : %s-%ld\n", p->plz.cc, p->plz.num);
    else
        printf("PLZ   : %ld\n", p->plz.num);
    printf("Tel   : %s\n", p->tel);
}

int main(void) {
    PDAT x;
    pdat_init(&x);

    /* demo values */
    strcpy(x.name, "Max Mustermann");
    strcpy(x.street, "Example Street 10");
    strcpy(x.plz.cc, "DE");
    x.plz.num = 91054;
    strcpy(x.tel, "09131-1234567");

    pdat_print(&x);
    return 0;
}
