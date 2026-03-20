#include "db_def.h"

/* ---------- display one record ---------- */
void show(PDAT *p) {
    printf("\n%s %s\n", p->vorname, p->nachname);
    printf("%s\n", p->wohnort);
    printf("%s\n", p->strasse);
    printf("PLZ: %s %ld\n", p->plz_lc[0] ? p->plz_lc : "", p->plz_num);
    printf("Tel: %s\n", p->telefon);
    printf("DOB: %02u.%02u.%04u\n", p->geb_tag, p->geb_monat, p->geb_jahr);
}

/* ---------- input helpers ---------- */
static void read_line(const char *prompt, char *dst, size_t cap) {
    char buf[INPUT_MAX];
    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(buf, sizeof(buf), stdin)) { dst[0] = '\0'; return; }
    buf[strcspn(buf, "\r\n")] = 0;
    if (strcmp(buf, "-") == 0) return;          /* keep default */
    strncpy(dst, buf, cap - 1);
    dst[cap - 1] = '\0';
}

static LONG read_long(const char *prompt, LONG def) {
    char buf[INPUT_MAX];
    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(buf, sizeof(buf), stdin)) return def;
    if (buf[0] == '-') return def;
    return labs(atol(buf));
}

static void read_date(const char *prompt, WORD *d, WORD *m, WORD *y) {
    char buf[INPUT_MAX];
    printf("%s (dd.mm.yyyy or '-'): ", prompt);
    fflush(stdout);
    if (!fgets(buf, sizeof(buf), stdin)) return;
    if (buf[0] == '-') return;
    unsigned dd=0, mm=0, yy=0;
    if (sscanf(buf, "%u.%u.%u", &dd, &mm, &yy) == 3) {
        *d = (WORD)dd; *m = (WORD)mm; *y = (WORD)yy;
    }
}

/* ---------- daten_init: allocate + fill ---------- */
int daten_init(PNODE node) {
    PDAT *dp = (PDAT*)calloc(1, sizeof(PDAT));
    if (!dp) return 0;

    /* default = previous record if exists */
    if (node->prev && node->prev->data) {
        *dp = *(PDAT*)node->prev->data;
    }

    printf("\nEnter data (type '-' to keep default)\n");
    read_line("First name: ", dp->vorname, sizeof(dp->vorname));
    read_line("Last name : ", dp->nachname, sizeof(dp->nachname));
    read_line("City      : ", dp->wohnort, sizeof(dp->wohnort));
    read_line("Street    : ", dp->strasse, sizeof(dp->strasse));
    read_line("Phone     : ", dp->telefon, sizeof(dp->telefon));

    /* postal code: country code + numeric */
    read_line("PLZ country code (3 chars) : ", dp->plz_lc, sizeof(dp->plz_lc));
    dp->plz_num = read_long("PLZ number               : ", dp->plz_num);

    read_date("Date of birth", &dp->geb_tag, &dp->geb_monat, &dp->geb_jahr);

    node->data = dp;
    return 1;
}

/* ---------- insert node into rotating DLL ---------- */
PNODE insert(PNODE liste, void *data) {
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if (!newn) return 0;

    if (!liste) {
        newn->prev = newn->next = newn;
    } else {
        newn->prev = liste;
        newn->next = liste->next;
        liste->next->prev = newn;
        liste->next = newn;
    }

    newn->data = NULL;

    if (data) {
        newn->data = data;
    } else {
        if (!daten_init(newn)) {
            free(newn);
            return (PNODE)-1; /* data alloc failed */
        }
    }
    return newn;
}

/* ---------- clear_node: unlink + free node ---------- */
PNODE clear_node(PNODE p) {
    PNODE save = (p && p->next != p) ? p->next : NULL;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return save;
}

/* ---------- clear: delete u/s ---------- */
LONG clear(PNODE *liste, LONG anz_rec, WORD action) {
    LONG clear_count = 0;
    if (!liste || !*liste || anz_rec <= 0) return 0;

    PNODE p = *liste;
    while (anz_rec--) {
        int del = 0;

        if (action == 'u') del = 1;
        else if (action == 's') {
            show((PDAT*)p->data);
            printf("Delete (y/n, z=abort)? ");
            fflush(stdout);
            int c = tolower(getchar());
            while (getchar() != '\n') {}
            if (c == 'z') break;
            del = (c == 'y');
        }

        if (del) {
            if (p->data) free(p->data);
            PNODE next = clear_node(p);
            clear_count++;
            if (!next) { p = NULL; break; }
            p = next;
        } else {
            p = p->next;
        }

        if (p && p->next == p) { /* last node left */
            *liste = p;
        }
    }

    *liste = p;
    return clear_count;
}

/* ---------- save: write all PDAT sequentially ---------- */
LONG save(PNODE liste) {
    char path[INPUT_MAX];
    printf("Filename (complete path): ");
    fflush(stdout);
    if (!fgets(path, sizeof(path), stdin)) return -1L;
    path[strcspn(path, "\r\n")] = 0;

    FILE *fp = fopen(path, "wb");
    if (!fp) return -1L;

    LONG count = 0;
    PNODE p = liste;
    if (p) {
        do {
            if (p->data) {
                if (fwrite(p->data, sizeof(PDAT), 1, fp) != 1) {
                    fclose(fp);
                    return -count; /* partial */
                }
                count++;
            }
            p = p->next;
        } while (p != liste);
    }
    fclose(fp);
    return count;
}

/* ---------- lesen: read file into list (append) ---------- */
LONG lesen(PNODE *liste) {
    char path[INPUT_MAX];
    printf("Filename (complete path): ");
    fflush(stdout);
    if (!fgets(path, sizeof(path), stdin)) return -1L;
    path[strcspn(path, "\r\n")] = 0;

    FILE *fp = fopen(path, "rb");
    if (!fp) return -1L;

    LONG count = 0;
    while (1) {
        PDAT *dp = (PDAT*)malloc(sizeof(PDAT));
        if (!dp) { fclose(fp); return -count; }

        size_t n = fread(dp, sizeof(PDAT), 1, fp);
        if (n != 1) {
            free(dp);
            if (break_oneof(fp)) break;
            fclose(fp);
            return -count;
        }

        PNODE p = insert(*liste, dp);
        if (p == 0) { free(dp); fclose(fp); return -count; }
        if (p == (PNODE)-1) { free(dp); fclose(fp); return -count; }

        *liste = p;
        count++;
    }

    fclose(fp);
    return count;
}

/* ---------- compare + swap for sorting ---------- */
LONG pdat_comp(PDAT *p1, PDAT *p2) {
    LONG x;
    if ((x = strcmp(p1->nachname, p2->nachname)) != 0) return x;
    if ((x = strcmp(p1->vorname, p2->vorname)) != 0) return x;
    if ((x = (LONG)p1->geb_jahr - (LONG)p2->geb_jahr) != 0) return x;
    if ((x = (LONG)p1->geb_monat - (LONG)p2->geb_monat) != 0) return x;
    if ((x = (LONG)p1->geb_tag - (LONG)p2->geb_tag) != 0) return x;
    if ((x = (LONG)p1->plz_num - (LONG)p2->plz_num) != 0) return x;
    if ((x = strcmp(p1->wohnort, p2->wohnort)) != 0) return x;
    if ((x = strcmp(p1->strasse, p2->strasse)) != 0) return x;
    return strcmp(p1->telefon, p2->telefon);
}

void pdat_swap(void **a, void **b) {
    void *t = *a; *a = *b; *b = t;
}

void L_sort(void **p, LONG count) {
    for (; count >= 2; count--) {
        for (LONG i = 0; i < count - 1; i++) {
            if (pdat_comp((PDAT*)p[i], (PDAT*)p[i+1]) > 0) {
                pdat_swap(&p[i], &p[i+1]);
            }
        }
    }
}

/* ---------- sort: pointer array sort, then write back to nodes ---------- */
LONG sort(PNODE liste, LONG count) {
    void **arr = (void**)malloc((size_t)count * sizeof(void*));
    if (!arr) return -1L;

    PNODE p = liste;
    LONG pcount = 0;
    do {
        arr[pcount++] = p->data;
        p = p->next;
    } while (p != liste && pcount < count);

    if (pcount != count) { free(arr); return pcount; } /* inconsistency */

    L_sort(arr, count);

    p = liste;
    for (LONG i = 0; i < count; i++) {
        p->data = arr[i];
        p = p->next;
    }

    free(arr);
    return count;
}
