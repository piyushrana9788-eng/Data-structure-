#include <stdio.h>

int main(void) {
    int n, a[100], found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Local maxima (strictly greater than existing neighbors): ");
    for (int i = 0; i < n; i++) {
        int left_ok = (i == 0 || a[i] > a[i - 1]);
        int right_ok = (i == n - 1 || a[i] > a[i + 1]);
        if (left_ok && right_ok) {
            printf("%d ", a[i]);
            found = 1;
        }
    }
    if (!found) printf("None");
    printf("\n");
    return 0;
}
