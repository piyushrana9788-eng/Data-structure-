#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[2000];
    int characters = 0, words = 0, spaces = 0, lines = 0, in_word = 0;
    printf("Enter text (finish with Ctrl+D on Linux/macOS or Ctrl+Z then Enter on Windows):\n");

    int ch;
    while ((ch = getchar()) != EOF) {
        characters++;
        if (ch == ' ') spaces++;
        if (ch == '\n') lines++;

        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            words++;
            in_word = 1;
        }
    }

    printf("Characters = %d\nWords = %d\nSpaces = %d\nLines = %d\n",
           characters, words, spaces, lines);
    return 0;
}
