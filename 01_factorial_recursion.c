#include <stdio.h>

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    int n;
    printf("Enter a non-negative number (0 to 20): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        printf("Invalid input. Enter a number from 0 to 20.\n");
        return 1;
    }

    printf("Factorial = %lld\n", factorial(n));
    return 0;
}
