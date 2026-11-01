#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (islower(ch)) s[i] = (char)toupper(ch);
        else if (isupper(ch)) s[i] = (char)tolower(ch);
    }

    printf("Toggle case: %s", s);
    return 0;
}
