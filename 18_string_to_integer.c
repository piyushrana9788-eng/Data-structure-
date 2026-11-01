#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

int main(void) {
    char s[200], *end;
    printf("Enter an integer as a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    errno = 0;
    long value = strtol(s, &end, 10);
    while (isspace((unsigned char)*end)) end++;

    if (s[0] == '\0' || end == s || *end != '\0' || errno == ERANGE ||
        value < -2147483647L - 1L || value > 2147483647L) {
        printf("Invalid integer string.\n");
        return 1;
    }

    printf("Integer value = %ld\n", value);
    return 0;
}
