#include <stdio.h>
#define MAX 1000

int a[MAX], n;
void post(int lo, int hi) {
    if (lo > hi)
        return;
    int root = a[lo], i = lo + 1;
    while (i <= hi && a[i] < root)
        i++;
    post(lo + 1, i - 1);
    post(i, hi);
    printf("%d ", root);
}

int main() {
    printf("Number of nodes: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
        return 0;
    puts("BST preorder:");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Postorder: ");
    post(0, n - 1);
    puts("");
    return 0;
}
