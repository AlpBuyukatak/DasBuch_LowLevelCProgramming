/* 12.1: Problem Description (book-aligned minimal example)
A simple address-management program concept:
- Keep personal records (name, address, telephone, etc.)
- Manipulate them via a menu (read/write/add/delete/sort/display/modify/quit)
This code shows ONLY the menu-driven skeleton (no real database yet).
*/

#include <stdio.h>

typedef enum {
    M_READ = 1,
    M_WRITE,
    M_ADD,
    M_DELETE,
    M_SORT,
    M_DISPLAY,
    M_MODIFY,
    M_QUIT
} MENU_CMD;

static MENU_CMD menu(void) {
    int sel = 0;

    puts("\n=== Address Management (Demo) ===");
    puts("1) Read records from file");
    puts("2) Write records to file");
    puts("3) Add record");
    puts("4) Delete record");
    puts("5) Sort records");
    puts("6) Display records");
    puts("7) Modify record");
    puts("8) Quit");
    printf("Select: ");

    if (scanf("%d", &sel) != 1) {
        /* invalid input -> clear stdin and return quit-like safe choice */
        int c; while ((c=getchar())!='\n' && c!=EOF) {}
        return M_QUIT;
    }
    return (MENU_CMD)sel;
}

int main(void) {
    for (;;) { /* infinite loop as described */
        MENU_CMD cmd = menu();
        switch (cmd) {
            case M_READ:    puts("[READ] not implemented yet");    break;
            case M_WRITE:   puts("[WRITE] not implemented yet");   break;
            case M_ADD:     puts("[ADD] not implemented yet");     break;
            case M_DELETE:  puts("[DELETE] not implemented yet");  break;
            case M_SORT:    puts("[SORT] not implemented yet");    break;
            case M_DISPLAY: puts("[DISPLAY] not implemented yet"); break;
            case M_MODIFY:  puts("[MODIFY] not implemented yet");  break;
            case M_QUIT:    puts("Bye."); return 0;
            default:        puts("Invalid selection.");            break;
        }
    }
}
