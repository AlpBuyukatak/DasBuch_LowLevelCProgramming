#include <stdio.h>

int main(void) {
    char *ctl[] = {"NUL","SOH","STX"};

    char c1 = ctl[1][1];
    char c2 = *(*(ctl + 1) + 1);

    printf("Index notation:   %c\n", c1);
    printf("Pointer notation: %c\n", c2);

    return 0;
}
