
//3.0 Pointer
/*The following example shows how you can use typedef to create a struct pointer */

#include <stdio.h>

int main() {

   typedef unsigned long int ULONG;
   typedef short int SHORT;

   typedef struct mystruct {
      ULONG a;
      SHORT b;
   } STR;

   STR s1 = {10, 20};
   typedef STR * strptr;
   strptr ptr = &s1;

   printf("%d %d \n", s1.a, s1.b);
   printf("%d %d", ptr->a, ptr->b);

   return 0;
}

//credited from "https://www.tutorialspoint.com/cprogramming/c_typedef.htm" 