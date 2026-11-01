#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *l, *r;
} Node;

Node *make(void) {
    int x;
    printf("Value (-1 for NULL): ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->l = n->r = NULL;
    printf("Enter left child of %d (strict tree nodes must have 0 or 2 children):\n", x);
    n->l = make();
    printf("Enter right child of %d:\n", x);
    n->r = make();
    if ((n->l == NULL) != (n->r == NULL)) {
        puts("Invalid: node has exactly one child.");
        exit(1);
    }
    return n;
}

void pre(Node *n) {
    if (n) {
        printf("%d ", n->data);
        pre(n->l);
        pre(n->r);
    }
}

int main() {
    puts("Build a strictly/full binary tree recursively.");
    Node *r = make();
    printf("Preorder: ");
    pre(r);
    puts("");
    return 0;
}
