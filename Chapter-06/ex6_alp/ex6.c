#include <stdio.h>

int main(void) {
    char a_ctl[3][4] = {"NUL","SOH","STX"};
    char *p_ctl[3]   = {"NUL","SOH","STX"};

    printf("a_ctl[1] = %s\n", a_ctl[1]);
    printf("p_ctl[1] = %s\n", p_ctl[1]);

    printf("\nAddresses:\n");
    printf("Address of a_ctl[1] = %p\n", (void*)a_ctl[1]);
    printf("Address of p_ctl[1] = %p\n", (void*)p_ctl[1]);

    return 0;
}
