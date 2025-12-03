#include <stdio.h>

int main(void) {
    char *p[] = {"NUL","SOH","STX"};

    printf("Before:\n");
    for (int i = 0; i < 3; i++)
        printf("p[%d] -> %s\n", i, p[i]);

    p[1] = "NEW TEXT";  // reinitialization

    printf("\nAfter:\n");
    for (int i = 0; i < 3; i++)
        printf("p[%d] -> %s\n", i, p[i]);

    /*
        Explanation:
        - "SOH" still exists in memory (as a string literal),
        - but p[1] no longer points to it.
        - Therefore "SOH" becomes an unreachable "orphan" string.
    */

    return 0;
}
