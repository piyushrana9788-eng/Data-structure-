#include <stdio.h>
#define MAX 100

int main(void)
{
    int stack[MAX], temp[MAX];
    int n, i, top = -1, tempTop = -1, value;

    printf("Enter number of elements (1-%d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) { scanf("%d", &value); stack[++top] = value; }

    while (top >= 0) {
        value = stack[top--];
        while (tempTop >= 0 && temp[tempTop] > value)
            stack[++top] = temp[tempTop--];
        temp[++tempTop] = value;
    }

    printf("Stack sorted in ascending order (bottom to top):\n");
    for (i = 0; i <= tempTop; i++) printf("%d ", temp[i]);
    printf("\n");
    return 0;
}
