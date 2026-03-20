#include <stdio.h>

int main(void) {
    char s1[] = "Dog";
    char s2[] = "Cat";
    char s3[] = "Fox";

    char *animals1[] = { s1, s2, s3 };   // group 1

    char *animals2[] = { "Red", "Blue", "Green" };  // group 2

    char **allAnimalGroups[] = { animals1, animals2 };

    char ***p = allAnimalGroups;

    // Örnek erişim: "Cat" içindeki 't' harfi
    printf("p[0][1][2] = %c\n", p[0][1][2]);  // => t

    // Örnek erişim: "Green" içindeki 'r' harfi
    printf("p[1][2][1] = %c\n", p[1][2][1]);  // => r

    return 0;
}
