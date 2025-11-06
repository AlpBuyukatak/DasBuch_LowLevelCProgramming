//1.4 Type Definition - page 23
#include <stdio.h>

// If we work on 16-bit system: 
typedef unsigned int UWORD;   // 16-bit unsigned int

// If we work on 32-bit system:
// typedef unsigned short UWORD;   // intended process; write this line instead of 5.line


int main() {
    UWORD value = 0xABCD;   // 16-bit value 

    printf("UWORD value: 0x%X\n", value);

    return 0;
}

