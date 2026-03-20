/*7.10 Structure Declarations - Page 111
Bit-field “mask” example (struct with bit fields)
*/

#include <stdio.h>
#include <stdint.h>

/* Example: bit-field structure */

typedef struct {
    unsigned bf1 : 4;  /* 4 bits  -> 0..15 */
    signed   bf2 : 6;  /* 6 bits  -> typically -32..31 */
    unsigned bf3 : 8;  /* 8 bits  -> 0..255 */
} MASK;

int main(void) {
    MASK mask = {0};

    /* Assign some example values */
    mask.bf1 = 12;
    mask.bf2 = -7;
    mask.bf3 = 200;

    printf("bf1=%u\n", mask.bf1);
    printf("bf2=%d\n", mask.bf2);
    printf("bf3=%u\n", mask.bf3);

    printf("sizeof(MASK)=%zu\n", sizeof(MASK)); /* compiler-dependent */
    return 0;
}
