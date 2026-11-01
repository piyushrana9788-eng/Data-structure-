#include <stdio.h>

int main(void) {
    int n, a[100], duplicate_values = 0, extra_occurrences = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        int seen_before = 0, occurrences = 0;
        for (int j = 0; j < i; j++)
            if (a[j] == a[i]) seen_before = 1;

        if (!seen_before) {
            for (int j = i; j < n; j++)
                if (a[j] == a[i]) occurrences++;
            if (occurrences > 1) {
                duplicate_values++;
                extra_occurrences += occurrences - 1;
            }
        }
    }

    printf("Distinct values that are duplicated = %d\n", duplicate_values);
    printf("Total extra duplicate occurrences = %d\n", extra_occurrences);
    return 0;
}
