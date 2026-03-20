#include "db_def.h"

static void clrscr(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void beep(void) {
    putchar('\a');
}

void meldung(const char *text) {
    beep();
    printf("\n*** %s ***\n", text);
    printf("Press ENTER...");
    fflush(stdout);
    while (getchar() != '\n') {}
}

WORD menu(LONG recordcount) {
    char buf[INPUT_MAX];
    clrscr();
    printf("Records in memory: %ld\n", recordcount);
    printf("1  Display records\n");
    printf("2  Add record\n");
    printf("3  Delete records (u/s)\n");
    printf("4  Save to file\n");
    printf("5  Read from file\n");
    printf("6  Sort records\n");
    printf("9  Quit\n");
    printf("Selection: ");
    fflush(stdout);

    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    return (WORD)atoi(buf);
}
