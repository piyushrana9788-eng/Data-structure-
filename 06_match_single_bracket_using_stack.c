#include <stdio.h>
#include <string.h>
#define MAX 300

int main(void)
{
    char expression[MAX], stack[MAX];
    int i, top = -1, balanced = 1;

    printf("Enter an expression containing brackets: ");
    if (fgets(expression, sizeof(expression), stdin) == NULL) return 1;

    for (i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            if (top == MAX - 1) { balanced = 0; break; }
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) { balanced = 0; break; }
            if ((c == ')' && stack[top] != '(') ||
                (c == ']' && stack[top] != '[') ||
                (c == '}' && stack[top] != '{')) {
                balanced = 0; break;
            }
            top--;
        }
    }

    if (top != -1) balanced = 0;
    if (balanced) printf("Brackets are balanced.\n");
    else printf("Brackets are not balanced.\n");
    return 0;
}
