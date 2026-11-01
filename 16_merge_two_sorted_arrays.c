#include <stdio.h>

int main(void) {
    int n, m, a[100], b[100], c[200];
    printf("Enter size of first sorted array: ");
    scanf("%d", &n);
    if (n < 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter first array in ascending order: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter size of second sorted array: ");
    scanf("%d", &m);
    if (m < 0 || m > 100) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter second array in ascending order: ");
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];

    printf("Merged sorted array: ");
    for (int p = 0; p < k; p++) printf("%d ", c[p]);
    printf("\n");
    return 0;
}
