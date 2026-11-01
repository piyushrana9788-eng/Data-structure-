#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500], copy[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;

    s[strcspn(s, "\n")] = '\0';
    strcpy(copy, s);
    printf("Copied string: %s\n", copy);
    return 0;
}
