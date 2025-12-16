/*7.10 Structure Declarations - Page 115
Union + time bit-fields example (Gettime demo)
*/

#include <stdio.h>
#include <stdint.h>

/* Example: union of a 16-bit integer and a bit-field time structure */

typedef union {
    struct {
        unsigned sec  : 5;  /* bits 0-4  -> seconds/2 (0..31) */
        unsigned min  : 6;  /* bits 5-10 -> minutes (0..63) */
        unsigned hour : 5;  /* bits 11-15-> hours (0..31) */
    } btime;
    uint16_t utime;
} TIME_U;

/* Simulated OS function returning a packed 16-bit time value */
static uint16_t Gettime_sim(unsigned hour, unsigned min, unsigned sec) {
    /* Store sec/2 in 5 bits */
    uint16_t s = (uint16_t)((sec / 2) & 0x1F);
    uint16_t m = (uint16_t)(min & 0x3F);
    uint16_t h = (uint16_t)(hour & 0x1F);
    return (uint16_t)( (h << 11) | (m << 5) | s );
}

int main(void) {
    TIME_U x;

    /* Example: 14:23:20 */
    x.utime = Gettime_sim(14, 23, 20);

    printf("packed utime = 0x%04X\n", x.utime);
    printf("%02u:%02u:%02u\n",
           x.btime.hour,
           x.btime.min,
           (unsigned)(x.btime.sec * 2));  /* seconds are stored as sec/2 */

    return 0;
}
