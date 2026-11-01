#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 300

int isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }

int main(void)
{
    char exp[MAX];
    double stack[MAX], a, b;
    int top = -1, i, len;

    printf("Enter prefix expression (single-digit non-negative operands, no spaces): ");
    if (scanf("%299s", exp) != 1) return 1;
    len = (int)strlen(exp);

    for (i = len - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit((unsigned char)c)) stack[++top] = c - '0';
        else if (isOperator(c)) {
            if (top < 1) { printf("Invalid prefix expression.\n"); return 1; }
            a = stack[top--];
            b = stack[top--];
            if (c == '+') stack[++top] = a + b;
            else if (c == '-') stack[++top] = a - b;
            else if (c == '*') stack[++top] = a * b;
            else if (c == '/') {
                if (b == 0) { printf("Division by zero.\n"); return 1; }
                stack[++top] = a / b;
            } else stack[++top] = pow(a, b);
        } else { printf("Invalid character.\n"); return 1; }
    }

    if (top != 0) { printf("Invalid prefix expression.\n"); return 1; }
    printf("Result: %.2f\n", stack[top]);
    return 0;
}
