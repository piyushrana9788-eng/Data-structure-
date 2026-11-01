#include <stdio.h>

int main(void) {
    int n, m, a[100], b[100], same = 1;
    printf("Enter size of first array: ");
    scanf("%d", &n);
    if (n < 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter first array: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &m);
    if (m < 0 || m > 100) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter second array: ");
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    if (n != m) same = 0;
    else {
        for (int i = 0; i < n; i++)
            if (a[i] != b[i]) same = 0;
    }

    if (same) printf("Arrays are the same.\n");
    else printf("Arrays are not the same.\n");
    return 0;
}
