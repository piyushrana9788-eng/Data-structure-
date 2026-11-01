#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    size_t start = 0, end = strlen(s);
    while (start < end && isspace((unsigned char)s[start])) start++;
    while (end > start && isspace((unsigned char)s[end - 1])) end--;

    size_t length = end - start;
    memmove(s, s + start, length);
    s[length] = '\0';

    printf("Trimmed string: \"%s\"\n", s);
    return 0;
}
