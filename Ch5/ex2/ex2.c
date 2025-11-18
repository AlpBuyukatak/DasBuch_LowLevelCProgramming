// 5.1.3. Array Addresses - page 79
/*
This code writes the text “Startwert eingeben”(Enter starting value) into the third row of the screen matrix. 
By using pointer arithmetic (screen[2] + 1), it positions the text starting at column 1 of that row. 
The custom strcpy2 function then copies the characters into that exact location on the screen.
*/
#include <stdio.h>

typedef unsigned char BYTE;

// Simple strcpy function
void strcpy2(BYTE *target, BYTE *source)
{
    while (*source != '\0')
        *target++ = *source++;

    *target = '\0'; // null-terminator
}

int main() {

    BYTE screen[25][80] = {0};

    BYTE text[] = "Startwert eingeben";

    // Row 3 (index 2), column 1 (index 1)
    strcpy2(screen[2] + 1, text);

    // Let's print only the relevant line for control purposes.
    for (int i = 0; i < 80; i++)
        putchar(screen[2][i] ? screen[2][i] : '.');  // add dots to empty spaces

    putchar('\n');

    return 0;
}

/*
strcpy is a function that copies text to another location. 
In this example, it was used to place the text "Startwert eingeben" in a specific 
row and column of the display matrix.
for example: 
char source[] = "Hello";
char dest[20];
strcpy(dest, source);

it turns into that:

'H' → dest[0]

'e' → dest[1]

'l' → dest[2]

'l' → dest[3]

'o' → dest[4]

'\0' → dest[5] (end of the string)
*/