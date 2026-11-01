#include <stdio.h>

int main(void) {
    int n, a[100], k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter k (1 to %d): ", n);
    scanf("%d", &k);
    if (k < 1 || k > n) {
        printf("Invalid k value.\n");
        return 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("The %d-th smallest value is %d\n", k, a[k - 1]);
    return 0;
}
