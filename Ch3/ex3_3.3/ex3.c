//3.3 Pointer as Return Value of a Function - page 50
/*
This code builds a static 2×2 matrix and returns it as a double** by creating an 
array of pointers that each point to a row; the main function then uses 
this double pointer to print the matrix elements.
*/
#include <stdio.h>

double **getArray() {  
    // defined as "**" because it's a 2D matrix (array of arrays)
    static double arr[2][2] = {
        {1.1, 2.2},
        {3.3, 4.4}
    };

    // result is a 1D array of pointers (each pointing to a row)
    static double *result[2];    

    for (int i = 0; i < 2; i++)      // arr[0] → {1.1, 2.2}, arr[1] → {3.3, 4.4}
        result[i] = arr[i];          // store address of each row

    return result;                   // returns double** 
}

int main() {
    double **p = getArray();         // function returns double** 

    // print values dynamically 
    int rows = 2;
    int cols = 2;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%.1f ", p[i][j]);
        printf("\n");
    }

    return 0;
}