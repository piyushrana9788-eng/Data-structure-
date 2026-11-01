#include <stdio.h>
#define MAX 200

int a[MAX], n, k, count = 0, answer, found = 0;
void revIn(int i) {
    if (i >= n || a[i] == -1 || found)
        return;
    revIn(2 * i + 2);
    if (found)
        return;
    if (++count == k) {
        answer = a[i];
        found = 1;
        return;
    }
    revIn(2 * i + 1);
}

int main() {
    printf("Array size: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
        return 0;
    printf("Enter BST array in level order (-1 for empty): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("k: ");
    scanf("%d", &k);
    revIn(0);
    if (found)
        printf("%dth largest: %d\n", k, answer);
    else
        puts("Invalid k");
    return 0;
}
