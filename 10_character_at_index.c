#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500];
    int index;
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    printf("Enter index (starting from 0): ");
    if (scanf("%d", &index) != 1) return 1;

    if (index >= 0 && (size_t)index < strlen(s))
        printf("Character at index %d = %c\n", index, s[index]);
    else
        printf("Invalid index.\n");
    return 0;
}
