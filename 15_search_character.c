#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500], ch;
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    printf("Enter a character to search: ");
    if (scanf(" %c", &ch) != 1) return 1;

    int found = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            printf("Character found at index %d\n", i);
            found = 1;
        }
    }
    if (!found) printf("Character not found.\n");
    return 0;
}
