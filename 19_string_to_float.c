#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

int main(void) {
    char s[200], *end;
    printf("Enter a floating-point number as a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    errno = 0;
    float value = strtof(s, &end);
    while (isspace((unsigned char)*end)) end++;

    if (s[0] == '\0' || end == s || *end != '\0' || errno == ERANGE || !isfinite(value)) {
        printf("Invalid float string.\n");
        return 1;
    }

    printf("Float value = %.6f\n", value);
    return 0;
}
