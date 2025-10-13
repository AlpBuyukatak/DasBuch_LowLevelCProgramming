#include <stdio.h>

int main(void) {
    unsigned long start = 0x1000;  // starting address
    unsigned long end   = 0x1FFF;  // ending address

    unsigned long total_bytes = end - start + 1;  // total bytes in the region
    unsigned long count = total_bytes / sizeof(double);  // how many doubles fit

    printf("Total bytes: %lu\n", total_bytes);
    printf("Size of one double: %zu bytes\n", sizeof(double));
    printf("Number of doubles that fit: %lu\n", count);

    return 0;
}
