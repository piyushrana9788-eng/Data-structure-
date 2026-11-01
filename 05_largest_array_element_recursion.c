#include <stdio.h>

int largest(int a[], int n) {
    if (n == 1) return a[0];
    int maxRest = largest(a, n - 1);
    return (a[n - 1] > maxRest) ? a[n - 1] : maxRest;
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

    printf("Largest element = %d\n", largest(a, n));
    return 0;
}
