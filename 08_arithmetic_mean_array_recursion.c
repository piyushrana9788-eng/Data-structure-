#include <stdio.h>

long long sumArray(int a[], int n) {
    if (n == 0) return 0;
    return a[n - 1] + sumArray(a, n - 1);
}

int main(void) {
    int n, a[100];
    printf("Enter number of elements (1 to 100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long long total = sumArray(a, n);
    printf("Arithmetic mean = %.2f\n", (double)total / n);
    return 0;
}
