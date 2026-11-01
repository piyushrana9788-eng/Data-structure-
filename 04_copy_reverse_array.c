#include <stdio.h>

int main(void) {
    int n, a[100], b[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) b[i] = a[n - 1 - i];

    printf("Copied in reverse order: ");
    for (int i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");
    return 0;
}
