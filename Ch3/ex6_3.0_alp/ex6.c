
//3.0 Pointer
/*The following example demonstrates how you can use alias names in a C program [TYPEDEF]  */

#include <stdio.h>

int main() {
   typedef short unsigned int USHORT;
   typedef signed long int SLONG;

   static SLONG x = 100;
   USHORT y = 200;

   printf("Size of SLONG: %d \nSize of USHORT: %d", sizeof(SLONG), sizeof(USHORT));
   
   return 0;
}

//credited from "https://www.tutorialspoint.com/cprogramming/c_typedef.htm" (ex6)