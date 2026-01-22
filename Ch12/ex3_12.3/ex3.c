/* 12.3: Main Program (book-aligned minimal example)
Main should be short and informative:
- Controlled by a menu in an infinite loop
- Uses a switch on the menu return value
- Delegates real work to project functions (read/write/add/delete/sort/show/modify)
This code shows the modular structure ONLY (stubs for functions).
*/

#include <stdio.h>

/* menu selections (keep numeric like book-style menus) */
enum {
    READ_REC = 1,
    WRITE_REC,
    ADD_REC,
    DELETE_REC,
    SORT_REC,
    DISPLAY_REC,
    MODIFY_REC,
    QUIT_REC
};

static int menu(void) {
    int sel = 0;
    puts("\n=== Address Management ===");
    puts("1 Read   2 Write  3 Add   4 Delete");
    puts("5 Sort   6 Display 7 Modify 8 Quit");
    printf("Select: ");
    if (scanf("%d", &sel) != 1) {
        int c; while ((c=getchar())!='\n' && c!=EOF) {}
        return QUIT_REC;
    }
    return sel;
}

/* --- project function stubs (to be implemented in 12.4+) --- */
static void read_records(void)   { puts("read_records() TBD"); }
static void write_records(void)  { puts("write_records() TBD"); }
static void add_record(void)     { puts("add_record() TBD"); }
static void delete_record(void)  { puts("delete_record() TBD"); }
static void sort_records(void)   { puts("sort_records() TBD"); }
static void display_records(void){ puts("display_records() TBD"); }
static void modify_record(void)  { puts("modify_record() TBD"); }

int main(void) {
    for (;;) {
        switch (menu()) {
            case READ_REC:     read_records();    break;
            case WRITE_REC:    write_records();   break;
            case ADD_REC:      add_record();      break;
            case DELETE_REC:   delete_record();   break;
            case SORT_REC:     sort_records();    break;
            case DISPLAY_REC:  display_records(); break;
            case MODIFY_REC:   modify_record();   break;
            case QUIT_REC:     puts("Bye."); return 0;
            default:           puts("Invalid selection."); break;
        }
    }
}
