#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *l, *r;
} Node;

Node *newNode(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->l = n->r = NULL;
    return n;
}

void preorder(Node *n) {
    if (n) {
        printf("%d ", n->data);
        preorder(n->l);
        preorder(n->r);
    }
}

int main() {
    int n, x;
    printf("Number of nodes: ");
    scanf("%d", &n);
    if (n <= 0 || n > 500)
        return 0;
    Node **a = malloc(n * sizeof(Node *));
    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i] = newNode(x);
    }
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n)
            a[i]->l = a[2 * i + 1];
        if (2 * i + 2 < n)
            a[i]->r = a[2 * i + 2];
    }
    printf("Complete binary tree preorder: ");
    preorder(a[0]);
    puts("");
    return 0;
}
