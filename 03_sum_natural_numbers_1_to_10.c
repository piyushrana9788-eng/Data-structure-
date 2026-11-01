#include <stdio.h>

int sumNatural(int n) {
    if (n <= 0) return 0;
    return n + sumNatural(n - 1);
}

int main(void) {
    printf("Sum of natural numbers from 1 to 10 = %d\n", sumNatural(10));
    return 0;
}
