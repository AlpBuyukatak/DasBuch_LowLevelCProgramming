//5.2 String Arrays - page 80
#include <stdio.h>

int main() {
    char msg[4][10] = {
        "Hi",
        "Hello",
        "ABC",
        "YOUCANTVIEW"
    };

    printf("%s\n", msg[0]);  // Hi
    printf("%s\n", msg[1]);  // Hello
    printf("%s\n", msg[2]); // ABC
    printf("%s\n", msg[3]); // as we can see, it wont be viewed perfectly
    printf("%c\n", msg[1][1]); // e

    return 0;
}

/*
msg[3][10] → 3 string, each one is max 9 characters (+ '\0')
*/