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

int main() {
    int n, x;
    printf("Number of nodes in level order (-1 for missing child): ");
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    printf("Root value: ");
    scanf("%d", &x);
    if (x == -1) {
        puts("Empty tree");
        return 0;
    }
    Node *root = newNode(x);
    Node **q = malloc((2 * n + 2) * sizeof(Node *));
    int f = 0, b = 0;
    q[b++] = root;
    for (int i = 0; i < n && f < b; i++) {
        Node *t = q[f++];
        printf("Left child of %d (-1 for none): ", t->data);
        scanf("%d", &x);
        if (x != -1) {
            t->l = newNode(x);
            q[b++] = t->l;
        }
        printf("Right child of %d (-1 for none): ", t->data);
        scanf("%d", &x);
        if (x != -1) {
            t->r = newNode(x);
            q[b++] = t->r;
        }
    }
    puts("Level order:");
    for (f = 0; f < b; f++) {
        printf("%d ", q[f]->data);
    }
    puts("");
    return 0;
}
