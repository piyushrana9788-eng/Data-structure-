#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (char)tolower((unsigned char)s[i]);

    printf("Lowercase: %s", s);
    return 0;
}
