#include <stdio.h>

// Absolute addressing easy level (simulated with a global variable at fixed address)
#define ABS_VAR (*(volatile int*)0x1000)

int main() {
    // 1. Direct Addressing
    int x = 10;
    int y = x * 2;   // direct use of variable
    printf("Direct: y = %d\n", y);

    // 2. Indirect Addressing (pointer)
    int z = 20;
    int *p = &z;     // p stores the address of z
    printf("Indirect: z = %d (via pointer)\n", *p);

    // 3. Absolute Addressing (for demo we just print the address)
    // In real embedded systems, 0x1000 would be a hardware register
    printf("Absolute: address = %p\n", (void*)&ABS_VAR);

    return 0;
}