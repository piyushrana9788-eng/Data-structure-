#include <stdio.h>

int sumDigits(unsigned int n) {
    if (n == 0) return 0;
    return (int)(n % 10) + sumDigits(n / 10);
}

int main(void) {
    long long number;
    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    unsigned int magnitude = (number < 0)
        ? (unsigned int)(-(number + 1)) + 1U
        : (unsigned int)number;

    printf("Sum of digits = %d\n", sumDigits(magnitude));
    return 0;
}
