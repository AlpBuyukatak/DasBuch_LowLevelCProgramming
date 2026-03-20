#include "db_def.h"

/* from db_term.c */
void meldung(const char *text);
WORD menu(LONG recordcount);

/* from db_list.c */
PNODE insert(PNODE liste, void *data);
LONG clear(PNODE *liste, LONG anz_rec, WORD action);
LONG save(PNODE liste);
LONG lesen(PNODE *liste);
LONG sort(PNODE liste, LONG count);
void show(PDAT *p);

int main(void) {
    PNODE liste = NULL;
    LONG recordcount = 0;
    WORD geaendert_flag = NEIN;

    for (;;) {
        WORD sel = menu(recordcount);

        switch (sel) {
        case ANZEIGEN: {
            if (!recordcount) { meldung("List is empty"); break; }
            PNODE p = liste;
            do {
                show((PDAT*)p->data);
                printf("Press ENTER for next...");
                fflush(stdout);
                while (getchar() != '\n') {}
                p = p->next;
            } while (p != liste);
        } break;

        case AUFNEHMEN: {
            PNODE p = insert(liste, NULL);
            if (p == 0) meldung("No memory space for node");
            else if (p == (PNODE)-1) meldung("No memory space for data");
            else {
                liste = p;
                recordcount++;
                geaendert_flag = JA;
            }
        } break;

        case LOESCHEN: {
            if (!recordcount) { meldung("List is empty"); break; }
            printf("Delete mode: u=unconditional, s=selective, z=cancel: ");
            fflush(stdout);
            int c = tolower(getchar());
            while (getchar() != '\n') {}
            if (c == 'z') break;
            if (c != 'u' && c != 's') { meldung("Invalid choice"); break; }

            LONG del = clear(&liste, recordcount, (WORD)c);
            if (del > 0) {
                recordcount -= del;
                geaendert_flag = JA;
                if (recordcount == 0) liste = NULL;
            }
        } break;

        case SPEICHERN: {
            if (!recordcount) { meldung("List is empty"); break; }
            if (geaendert_flag == NEIN) {
                printf("List not changed - save anyway? (y/n): ");
                fflush(stdout);
                int c = tolower(getchar());
                while (getchar() != '\n') {}
                if (c != 'y') break;
            }
            LONG ret = save(liste);
            if (ret == -1) meldung("File error: not written");
            else if (ret < 0) meldung("File error: only partially written");
            else { meldung("All records written"); geaendert_flag = NEIN; }
        } break;

        case LESEN: {
            /* If list exists, ask to delete first (like book) */
            if (recordcount) {
                printf("Delete existing list before reading? (y/n): ");
                fflush(stdout);
                int c = tolower(getchar());
                while (getchar() != '\n') {}
                if (c == 'y') {
                    clear(&liste, recordcount, 'u');
                    liste = NULL;
                    recordcount = 0;
                    geaendert_flag = NEIN;
                }
            }
            LONG got = lesen(&liste);
            if (got == -1) meldung("File error: not read");
            else if (got < 0) { meldung("Not enough memory - only partially read"); recordcount += -got; geaendert_flag = JA; }
            else { meldung("All records read"); recordcount += got; geaendert_flag = JA; }
        } break;

        case SORTIEREN: {
            if (!recordcount) meldung("List is empty");
            else if (recordcount == 1) meldung("Only one record present");
            else {
                LONG sc = sort(liste, recordcount);
                if (sc == -1) meldung("Not enough memory - list not sorted");
                else if (sc != recordcount) meldung("Error in data set");
                else { meldung("Sorted"); geaendert_flag = JA; }
            }
        } break;

        case QUIT:
            if (recordcount && geaendert_flag == JA) {
                meldung("Changes not saved!");
                /* keep running */
            } else {
                /* cleanup */
                if (recordcount) clear(&liste, recordcount, 'u');
                return 0;
            }
            break;

        default:
            meldung("Invalid selection");
            break;
        }
    }
}
