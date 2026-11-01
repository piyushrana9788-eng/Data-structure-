#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 300

int precedence(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
int isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^'; }

int main(void)
{
    char infix[MAX], postfix[MAX], stack[MAX];
    int i, j = 0, top = -1;

    printf("Enter infix expression (single-character operands, no spaces): ");
    if (scanf("%299s", infix) != 1) return 1;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum((unsigned char)c)) postfix[j++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') postfix[j++] = stack[top--];
            if (top < 0) { printf("Mismatched parentheses.\n"); return 1; }
            top--;
        } else if (isOperator(c)) {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                    (precedence(stack[top]) == precedence(c) && c != '^')))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        } else {
            printf("Unsupported character: %c\n", c);
            return 1;
        }
    }
    while (top >= 0) {
        if (stack[top] == '(') { printf("Mismatched parentheses.\n"); return 1; }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    printf("Note: operands must be single letters/digits; use no spaces.\n");
    return 0;
}
