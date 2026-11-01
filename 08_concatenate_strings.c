#include <stdio.h>
#include <string.h>

int main(void) {
    char a[500], b[500], result[1000];
    printf("Enter first string: ");
    if (!fgets(a, sizeof a, stdin)) return 1;
    printf("Enter second string: ");
    if (!fgets(b, sizeof b, stdin)) return 1;

    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';

    snprintf(result, sizeof result, "%s%s", a, b);
    printf("Concatenated string: %s\n", result);
    return 0;
}
