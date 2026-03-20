/* 12.6: Data Backup – function save (book-aligned minimal)
- Open a backup file and write records sequentially using fwrite.
- Return value represents success or error.
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

/* returns:
   -1 open/write-protected error
   >0 number of records written
*/
int save(const char *filename, const PDAT *arr, int n) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return -1;

    int written = 0;
    for (int i=0; i<n; i++) {
        if (fwrite(&arr[i], sizeof(PDAT), 1, fp) != 1) {
            fclose(fp);
            return -1; /* minimal: treat as error */
        }
        written++;
    }

    fclose(fp);
    return written;
}

int main(void) {
    PDAT rec[2];
    memset(rec, 0, sizeof(rec));

    strcpy(rec[0].vorname, "Max");
    strcpy(rec[0].nachname, "Muster");
    strcpy(rec[0].plz.cc, "DE");
    rec[0].plz.num = 91054;
    strcpy(rec[0].telefon, "09131-1111111");

    strcpy(rec[1].vorname, "Anna");
    strcpy(rec[1].nachname, "Beispiel");
    rec[1].plz.num = 10000;
    strcpy(rec[1].telefon, "030-2222222");

    int r = save("backup.dat", rec, 2);
    if (r < 0) puts("File error (could not write).");
    else       printf("Written records: %d\n", r);

    return 0;
}
