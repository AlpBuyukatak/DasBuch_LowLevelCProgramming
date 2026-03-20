/* 12.8: Reading Records – function lesen (book-aligned minimal)
- Open file for reading ("rb")
- Read PDAT records sequentially using fread
- Return value: number of records read (>=0) or -1 on file error
- No list rebuilding here; just demonstrate the core read loop
*/

#include <stdio.h>
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

/* returns: -1 file error, else count read */
int lesen(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;

    int count = 0;
    PDAT rec;
    while (fread(&rec, sizeof(PDAT), 1, fp) == 1) {
        printf("[%d] %s %s, ", count + 1, rec.vorname, rec.nachname);
        if (rec.plz.cc[0] != '\0') printf("%s-%ld, ", rec.plz.cc, rec.plz.num);
        else                      printf("%ld, ", rec.plz.num);
        printf("%s\n", rec.telefon);
        count++;
    }

    fclose(fp);
    return count;
}

int main(void) {
    int r = lesen("backup.dat");
    if (r < 0) puts("File error (could not read).");
    else       printf("Records read: %d\n", r);
    return 0;
}
