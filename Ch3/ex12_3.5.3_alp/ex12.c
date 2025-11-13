//3.5.3 Subtraction of Pointers
/*This code interprets two raw addresses as double* pointers and uses pointer 
subtraction to calculate how many double-sized elements fit between them. 
It prints the start address, the end address, and the number of doubles that can be stored in that memory range.
*/
#include <stdio.h>

int main(void) {
    // Define the start and end addresses
    double *start = (double *)0x1000;        // starting address (as a pointer)
    double *end   = (double *)(0x1FFF + 1);  // one past the last address

    // Pointer subtraction gives the number of double-sized steps between them
    long count = end - start;

    printf("Start address : %p\n", (void*)start);
    printf("End address   : %p\n", (void*)end);
    printf("Number of doubles that fit: %ld\n", count);

    return 0;
}
// each double is 8 byte, so 4096/8