#include <stdio.h>
#include <string.h>
#define MAX 200

int main(void)
{
    char text[MAX], stack[MAX];
    int i, top = -1;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) return 1;
    text[strcspn(text, "\n")] = '\0';

    for (i = 0; text[i] != '\0'; i++) stack[++top] = text[i];

    printf("Reversed string: ");
    while (top >= 0) putchar(stack[top--]);
    putchar('\n');
    return 0;
}
