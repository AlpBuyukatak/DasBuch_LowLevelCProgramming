/* 7.5: Size of structures and padding 
The compiler may insert padding bytes into a structure to satisfy alignment requirements, 
so the structure size can be larger than the sum of its members.*/

#include <stdio.h>

typedef struct {
    char  c;   // 1 byte
    int   i;   // typically 4 bytes (needs alignment)
    char  d;   // 1 byte
} S1;

typedef struct {
    int   i;   // 4 bytes
    char  c;   // 1 byte
    char  d;   // 1 byte
} S2;

int main(void) {
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(int)  = %zu\n\n", sizeof(int));

    printf("sizeof(S1) = %zu\n", sizeof(S1));
    printf("sizeof(S2) = %zu\n", sizeof(S2));

    return 0;
}
