//3.5.3 Subtraction of Pointers - page 57
/*
This code interprets two raw addresses as double* pointers and subtracts them to compute 
how many double elements fit in the memory range 0x1000–0x1FFF. It prints the result 
using both pointer subtraction and a direct address calculation.
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Memory range: 0x1000 – 0x1FFF (inclusive)
    // How many doubles can be stored there?

    double *anfang = (double *) 0x1000L;          // start address
    double *ende   = (double *) (0x1FFF + 1L);    // end address + 1

    long anzahl = ende - anfang;                  // pointer arithmetic

    printf("Number of doubles: %ld\n", anzahl);

    // Alternative direct calculation
    long anzahl2 = (double *) 0x2000L - (double *) 0x1000L;
    printf("Direct calculation: %ld\n", anzahl2);

    return 0;
}
