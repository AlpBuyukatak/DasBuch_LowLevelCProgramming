/* 12.11: Function Prototypes (book-aligned minimal)
Idea:
- Collect required prototypes in a separate header (e.g., DB_PORTA.H)
- Makes porting and project overview easier
This single-file demo shows:
  1) a "header-style" prototype block
  2) matching implementations
*/

#include <stdio.h>

/* ===== DB_PORTA.H (prototype block) ===== */
typedef struct PDAT PDAT;
typedef struct NODE *PNODE;

void  show(void *data);
PNODE insert(PNODE list);
int   daten_init(PDAT *d);
int   save(PNODE list, const char *filename);
int   lesen(PNODE *plist, const char *filename);
PNODE clear_all(PNODE list);
int   sort(PNODE list);
int   modify(PNODE list);
/* ======================================= */

/* minimal dummy types to satisfy compiler */
struct PDAT { int dummy; };
struct NODE { struct NODE *next,*prev; void *data; };

/* minimal dummy implementations */
void show(void *data) { (void)data; puts("show()"); }
PNODE insert(PNODE list){ (void)list; puts("insert()"); return NULL; }
int daten_init(PDAT *d){ (void)d; puts("daten_init()"); return 1; }
int save(PNODE list, const char *fn){ (void)list; (void)fn; puts("save()"); return 0; }
int lesen(PNODE *plist, const char *fn){ (void)plist; (void)fn; puts("lesen()"); return 0; }
PNODE clear_all(PNODE list){ (void)list; puts("clear_all()"); return NULL; }
int sort(PNODE list){ (void)list; puts("sort()"); return 0; }
int modify(PNODE list){ (void)list; puts("modify()"); return 0; }

int main(void) {
    puts("Prototype discipline demo (12.11).");
    return 0;
}
