#include <stdio.h>

int main(void) {
    const char *de[] = {"DE A", "DE B", "DE C"};
    const char *en[] = {"EN A", "EN B", "EN C"};

    const char **all_msg[] = {de, en};
    const char ***p = all_msg;

    int lang, idx;

    printf("Language? (0=DE, 1=EN): ");
    scanf("%d", &lang);

    printf("Index (0-2): ");
    scanf("%d", &idx);

    printf("Index notation:   %s\n", p[lang][idx]);
    printf("Pointer notation: %s\n", *(*(p + lang) + idx));

    return 0;
}
