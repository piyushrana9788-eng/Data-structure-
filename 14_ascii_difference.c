#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    if (s[0] == '\0') {
        printf("String is empty.\n");
        return 0;
    }

    printf("ASCII differences between adjacent characters:\n");
    for (int i = 0; s[i + 1] != '\0'; i++)
        printf("%c to %c: %d\n", s[i], s[i + 1],
               (int)(unsigned char)s[i + 1] - (int)(unsigned char)s[i]);
    return 0;
}
