#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500], ch;
    int index = -1;
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            index = i;
            break;
        }
    }

    printf("Index = %d\n", index);
    return 0;
}
