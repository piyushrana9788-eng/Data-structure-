#include <stdio.h>

int isPalindrome(int number) {
    if (number < 0) return 0;
    int original = number, reversed = 0;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return original == reversed;
}

int main(void) {
    int n, a[100], found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Palindrome numbers: ");
    for (int i = 0; i < n; i++) {
        if (isPalindrome(a[i])) {
            printf("%d ", a[i]);
            found = 1;
        }
    }
    if (!found) printf("None");
    printf("\n");
    return 0;
}
