//1.1.4 Sign Attributes 
#include <stdio.h>

int main() {
    int sflag = 0x80000000;          // signed int with MSB set
    unsigned int uflag = 0x80000000; // unsigned int with MSB set

    printf("sflag = %d\n", sflag);
    printf("uflag = %u\n", uflag);

    if (sflag > 0)
        printf("sflag > 0 (signed)\n");
    else
        printf("sflag < 0 (signed)\n");

    if (uflag > 0)
        printf("uflag > 0 (unsigned)\n");
    else
        printf("uflag < 0 (unsigned)\n");

    return 0;
}

/* With int, the MSB is treated as the sign bit, so the number becomes negative.
With unsigned int, the same bits are always interpreted as a positive value, which is correct for flags.  */