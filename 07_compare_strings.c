#include <stdio.h>
#include <string.h>

int main(void) {
    char a[500], b[500];
    printf("Enter first string: ");
    if (!fgets(a, sizeof a, stdin)) return 1;
    printf("Enter second string: ");
    if (!fgets(b, sizeof b, stdin)) return 1;

    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';

    if (strcmp(a, b) == 0) printf("Strings are equal.\n");
    else printf("Strings are not equal.\n");
    return 0;
}
