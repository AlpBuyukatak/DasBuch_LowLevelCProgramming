#include <stdio.h>

int main() {
    char msgA[] = "Hello";
    char msgB[] = "World";
    char msgC[] = "Test";

    char *group1[] = { msgA, msgB, msgC };
    char *group2[] = { "ABC", "DEF", "GHI" };

    char **groups[] = { group1, group2 };
    char ***p = groups;

    printf("p[1][0][2] = %c\n", p[1][0][2]);
    // Output: C

    return 0;
}
