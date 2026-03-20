/*7.5 Structure Declarations - Page 104
(padding/alignment)
*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

/* Example: size of structures depends on padding/alignment
   Book assumption (example): long=4, char=1, alignment to 2 bytes
   Expected (book): sizeof(s1)=12, sizeof(s2)=10 (under those rules)
*/

/* Use fixed-size types to make member sizes stable */
typedef uint8_t  BYTE;
typedef uint32_t LONG;

/* These layouts match the book's idea (BYTE, LONG, BYTE, LONG) */
typedef struct { BYTE c1; LONG l1; BYTE c2; LONG l2; } S1;
typedef struct { BYTE c1; LONG c2; BYTE l1; LONG l2; } S2;

static void dump_layout(const char *name, size_t sz, size_t o1, size_t o2, size_t o3, size_t o4) {
    printf("%s:\n", name);
    printf("  sizeof = %zu\n", sz);
    printf("  offsets: c1=%zu, l1=%zu, c2=%zu, l2=%zu\n\n", o1, o2, o3, o4);
}

int main(void) {
    printf("sizeof(BYTE) = %zu\n", sizeof(BYTE));
    printf("sizeof(LONG) = %zu\n\n", sizeof(LONG));

    dump_layout("S1",
                sizeof(S1),
                offsetof(S1, c1), offsetof(S1, l1), offsetof(S1, c2), offsetof(S1, l2));

    dump_layout("S2",
                sizeof(S2),
                offsetof(S2, c1), offsetof(S2, c2), offsetof(S2, l1), offsetof(S2, l2));

    return 0;
}
