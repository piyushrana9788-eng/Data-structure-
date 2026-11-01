#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[500];
    int count = 0;
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = (char)tolower((unsigned char)s[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;
    }

    printf("Number of vowels = %d\n", count);
    return 0;
}
