#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500];
    int width, option;
    printf("Enter text: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    printf("Enter output width: ");
    if (scanf("%d", &width) != 1 || width < 1 || width > 200) {
        printf("Invalid width.\n");
        return 1;
    }
    printf("Alignment (1=Left, 2=Center, 3=Right): ");
    if (scanf("%d", &option) != 1 || option < 1 || option > 3) {
        printf("Invalid alignment option.\n");
        return 1;
    }

    int len = (int)strlen(s);
    if (len > width) {
        printf("Text is longer than output width: %s\n", s);
        return 0;
    }

    int padding = width - len;
    int spaces = (option == 1) ? 0 : (option == 2 ? padding / 2 : padding);
    for (int i = 0; i < spaces; i++) putchar(' ');
    printf("%s\n", s);
    return 0;
}
