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

void view(Node *n, int level, int *maxLevel) {
    if (!n)
        return;
    if (level == *maxLevel) {
        printf("%d ", n->data);
        (*maxLevel)++;
    }
    Node *a[] = {n->r, n->l};
    view(a[0], level + 1, maxLevel);
    view(a[1], level + 1, maxLevel);
}

int main() {
    int n, x;
    printf("Number of nodes to enter: ");
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    printf("Root value: ");
    scanf("%d", &x);
    if (x == -1)
        return 0;
    Node *root = newNode(x);
    Node **q = malloc((2 * n + 2) * sizeof(Node *));
    int f = 0, b = 0;
    q[b++] = root;
    for (int i = 0; i < n && f < b; i++) {
        Node *t = q[f++];
        printf("Left child of %d (-1 none): ", t->data);
        scanf("%d", &x);
        if (x != -1) {
            t->l = newNode(x);
            q[b++] = t->l;
        }
        printf("Right child of %d (-1 none): ", t->data);
        scanf("%d", &x);
        if (x != -1) {
            t->r = newNode(x);
            q[b++] = t->r;
        }
    }
    int m = 0;
    printf("Right view: ");
    view(root, 0, &m);
    puts("");
    return 0;
}
