// 5.1.3. Array Addresses - page 78
/*
This code fills each row of the 2D array using a pointer. The pointer p is set to the start 
of the current row, and the column index values (0, 1, 2, 3) are written sequentially. 
As a result, every row ends up containing the same column indices.
*/

#include <stdio.h>
#define ROWS    10
#define COLUMNS 4

typedef unsigned char BYTE;

int main() {

    BYTE arr[ROWS][COLUMNS];
    BYTE *p;          // pointer
    unsigned int idx; // line number
    unsigned int val; // column value

    // For each line
    for (idx = 0; idx < ROWS; idx++)
    {
        p = arr[idx];     // p → starting address of that line
        val = 0;

        // For each column
        while (val < COLUMNS)
            *p++ = val++;   // write first, then advance the pointer
    }

    // Printing for control purposes
    for (idx = 0; idx < ROWS; idx++){
        for (val = 0; val < COLUMNS; val++)
            printf("%d ", arr[idx][val]);
        printf("\n");
    }

    return 0;
}
