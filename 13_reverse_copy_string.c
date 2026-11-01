#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500], reversed[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++) reversed[i] = s[n - 1 - i];
    reversed[n] = '\0';

    printf("Reversed copy: %s\n", reversed);
    return 0;
}
