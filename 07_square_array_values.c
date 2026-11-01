#include <stdio.h>

int main(void) {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Squares: ");
    for (int i = 0; i < n; i++) printf("%lld ", (long long)a[i] * a[i]);
    printf("\n");
    return 0;
}
