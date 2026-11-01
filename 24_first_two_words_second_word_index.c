#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    printf("Enter a sentence: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    int i = 0;
    while (s[i] != '\0' && isspace((unsigned char)s[i])) i++;
    while (s[i] != '\0' && !isspace((unsigned char)s[i])) i++;
    while (s[i] != '\0' && isspace((unsigned char)s[i])) i++;

    if (s[i] == '\0' || s[i] == '\n') {
        printf("Second word does not exist. Index = -1\n");
        return 0;
    }

    printf("First word: ");
    int j = 0;
    while (s[j] != '\0' && !isspace((unsigned char)s[j])) putchar(s[j++]);
    printf("\nSecond word: ");
    while (s[i] != '\0' && !isspace((unsigned char)s[i])) putchar(s[i++]);
    printf("\nStart index of second word = %d\n", j);
    return 0;
}
