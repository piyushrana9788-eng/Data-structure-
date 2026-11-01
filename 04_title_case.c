#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    int new_word = 1;
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (isalpha(ch)) {
            s[i] = (char)(new_word ? toupper(ch) : tolower(ch));
            new_word = 0;
        } else {
            new_word = isspace(ch) || ispunct(ch);
        }
    }

    printf("Title case: %s", s);
    return 0;
}
