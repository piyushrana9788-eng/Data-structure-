#include <stdio.h>

int main(void) {
    int n, a[100], found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Positive numbers: ");
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            printf("%d ", a[i]);
            found = 1;
        }
    }
    if (!found) printf("None");
    printf("\n");
    return 0;
}
