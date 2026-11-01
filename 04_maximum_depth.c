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

int depth(Node *n) {
    if (!n)
        return 0;
    int a = depth(n->l), b = depth(n->r);
    return 1 + (a > b ? a : b);
}

Node *readTree() {
    int x;
    printf("Node value (-1 for NULL): ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    Node *n = newNode(x);
    printf("Left of %d\n", x);
    n->l = readTree();
    printf("Right of %d\n", x);
    n->r = readTree();
    return n;
}

int main() {
    puts("Enter tree in preorder; use -1 for missing nodes.");
    Node *r = readTree();
    printf("Maximum depth: %d\n", depth(r));
    return 0;
}
