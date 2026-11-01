#include <stdio.h>

int main(void) {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int maximum = a[0], minimum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maximum) maximum = a[i];
        if (a[i] < minimum) minimum = a[i];
    }

    printf("Maximum = %d\nMinimum = %d\n", maximum, minimum);
    return 0;
}
