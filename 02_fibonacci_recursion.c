#include <stdio.h>

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int n;
    printf("Enter the number of Fibonacci terms (1 to 40): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 40) {
        printf("Invalid input. Enter a number from 1 to 40.\n");
        return 1;
    }

    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) printf("%lld ", fibonacci(i));
    printf("\n");
    return 0;
}
