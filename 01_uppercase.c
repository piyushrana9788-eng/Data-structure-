#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (char)toupper((unsigned char)s[i]);

    printf("Uppercase: %s", s);
    return 0;
}
