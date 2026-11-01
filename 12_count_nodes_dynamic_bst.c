#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *l, *r;
} Node;

Node *insert(Node *n, int x) {
    if (!n) {
        n = malloc(sizeof(Node));
        n->data = x;
        n->l = n->r = NULL;
    } else if (x < n->data)
        n->l = insert(n->l, x);
    else if (x > n->data)
        n->r = insert(n->r, x);
    return n;
}

int count(Node *n) {
    return n ? 1 + count(n->l) + count(n->r) : 0;
}

void inorder(Node *n) {
    if (n) {
        inorder(n->l);
        printf("%d ", n->data);
        inorder(n->r);
    }
}

int main() {
    Node *r = NULL;
    int n, x;
    printf("Number of values: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        r = insert(r, x);
    }
    printf("BST inorder: ");
    inorder(r);
    printf("\nNumber of nodes: %d\n", count(r));
    return 0;
}
