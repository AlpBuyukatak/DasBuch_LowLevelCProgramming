/* 12.10: Modifying Records (book-aligned minimal)
- Select a record (here: single record for simplicity)
- Modify components (e.g., telephone or name fields)
- Shows the idea of updating stored data in-place
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char vorname[32];
    char nachname[32];
    char telefon[14];
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

/* modify: only one field as core demonstration */
void modify_tel(PDAT *p) {
    char in[64];
    printf("Current telephone: %s\n", p->telefon);
    read_line("New telephone (empty = keep): ", in, sizeof(in));
    if (in[0] != '\0') {
        strncpy(p->telefon, in, sizeof(p->telefon)-1);
    }
}

int main(void) {
    PDAT r;
    memset(&r, 0, sizeof(r));
    strcpy(r.vorname, "Max");
    strcpy(r.nachname, "Mustermann");
    strcpy(r.telefon, "09131-1234567");

    puts("Before modify:");
    printf("%s %s, %s\n", r.vorname, r.nachname, r.telefon);

    modify_tel(&r);

    puts("\nAfter modify:");
    printf("%s %s, %s\n", r.vorname, r.nachname, r.telefon);

    return 0;
}
