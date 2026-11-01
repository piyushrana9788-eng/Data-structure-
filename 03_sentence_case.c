#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    int new_sentence = 1;
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (isalpha(ch)) {
            s[i] = (char)(new_sentence ? toupper(ch) : tolower(ch));
            new_sentence = 0;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
            new_sentence = 1;
    }

    printf("Sentence case: %s", s);
    return 0;
}
