#include <stdio.h>

void printBinary(unsigned int n) {
    if (n > 1) printBinary(n / 2);
    printf("%u", n % 2);
}

int main(void) {
    int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Enter a non-negative integer.\n");
        return 1;
    }

    printf("Binary = ");
    printBinary((unsigned int)n);
    printf("\n");
    return 0;
}
