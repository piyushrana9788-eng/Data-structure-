#include <stdio.h>
#include <string.h>

int main(void) {
    char s[11];
    int ascii[10];

    printf("Enter exactly 10 characters: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    int length = (int)strlen(s);
    if (length != 10) {
        printf("Please enter exactly 10 characters (not including Enter).\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
        ascii[i] = (unsigned char)s[i];

    printf("Character and ASCII value:\n");
    for (int i = 0; i < 10; i++)
        printf("%c -> %d\n", s[i], ascii[i]);

    printf("Integer array: ");
    for (int i = 0; i < 10; i++) printf("%d ", ascii[i]);
    printf("\n");
    return 0;
}
