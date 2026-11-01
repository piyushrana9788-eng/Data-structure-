#include <stdio.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++)
        printf("%c\n", s[i]);
    return 0;
}
