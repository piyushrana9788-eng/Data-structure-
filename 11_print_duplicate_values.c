#include <stdio.h>

int main(void) {
    int n, a[100], printed[100], count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Duplicate values: ");
    for (int i = 0; i < n; i++) {
        int seen_before = 0, appears_again = 0;
        for (int j = 0; j < i; j++)
            if (a[j] == a[i]) seen_before = 1;
        for (int j = i + 1; j < n; j++)
            if (a[j] == a[i]) appears_again = 1;

        if (!seen_before && appears_again) {
            printf("%d ", a[i]);
            count++;
        }
    }
    if (count == 0) printf("None");
    printf("\n");
    return 0;
}
