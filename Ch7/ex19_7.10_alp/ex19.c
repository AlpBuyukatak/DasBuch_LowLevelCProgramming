/* 7.10: Bit Fields (book-aligned example)
Bit fields allow structure components to occupy a specified number of bits.
They are typically used to represent hardware registers or flags.
Bit fields have no address and cannot be indexed.
Their layout and size are implementation dependent and not portable.
*/

#include <stdio.h>

struct FLAGS {
    unsigned ready : 1;
    unsigned error : 1;
    unsigned mode  : 2;
};

int main(void) {
    struct FLAGS f = {1, 0, 3};

    printf("ready=%u error=%u mode=%u\n",
           f.ready, f.error, f.mode);

    return 0;
}
