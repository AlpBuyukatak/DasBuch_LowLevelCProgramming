/*7.10 Structure Declarations - Page 114
Peripheral-style example — “ports wired at addresses
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Example: hardware register access via a struct pointer (SIMULATED)
   Real hardware addresses would crash on a normal PC, so we emulate memory.
*/

#define B1200  1
#define P11    10
#define GERMAN 6

typedef struct {
    uint16_t baud;
    uint16_t paper_length;
    uint8_t  charset;
    uint8_t  online;
    uint8_t  ready;
    uint8_t  pad;          /* padding to keep layout simple */
} PRT_CON;

/* Simulated memory-mapped register block */
static PRT_CON fake_port;

static void print_buffer(const char *s) {
    printf("PRINT: %s\n", s);
}

int main(void) {
    /* Pointer to "hardware registers" (here: simulated) */
    PRT_CON *prt = &fake_port;

    /* Initialize simulated status flags */
    prt->online = 1;
    prt->ready  = 1;

    if (prt->online && prt->ready) {
        prt->baud = B1200;
        prt->paper_length = P11;
        prt->charset = GERMAN;
        print_buffer("Hello printer");
    } else {
        printf("Printer not ready.\n");
    }

    printf("baud=%u, paper=%u, charset=%u\n",
           prt->baud, prt->paper_length, prt->charset);

    return 0;
}
