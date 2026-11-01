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

void level(Node *r) {
    if (!r)
        return;
    Node *q[1000];
    int f = 0, b = 0;
    q[b++] = r;
    while (f < b) {
        Node *t = q[f++];
        printf("%d ", t->data);
        if (t->l)
            q[b++] = t->l;
        if (t->r)
            q[b++] = t->r;
    }
}

int main() {
    int n, x;
    printf("Number of nodes: ");
    scanf("%d", &n);
    if (n <= 0 || n > 500)
        return 0;
    printf("Enter %d values in level order: ", n);
    Node **a = malloc(n * sizeof(Node *));
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
    /* An almost complete tree is represented by filling each level left-to-right, with final level possibly partial. */
    printf("Level order: ");
    level(a[0]);
    puts("");
    return 0;
}
