#include <stdio.h>

int smallest(int a[], int n) {
    if (n == 1) return a[0];
    int minRest = smallest(a, n - 1);
    return (a[n - 1] < minRest) ? a[n - 1] : minRest;
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

    printf("Smallest element = %d\n", smallest(a, n));
    return 0;
}
