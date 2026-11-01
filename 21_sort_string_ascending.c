#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j + 1 < n - i; j++) {
            if ((unsigned char)s[j] > (unsigned char)s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("Sorted string: %s\n", s);
    return 0;
}
