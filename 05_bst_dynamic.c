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

Node *minimum(Node *n) {
    while (n && n->l)
        n = n->l;
    return n;
}

Node *del(Node *n, int x) {
    if (!n)
        return NULL;
    if (x < n->data)
        n->l = del(n->l, x);
    else if (x > n->data)
        n->r = del(n->r, x);
    else {
        if (!n->l) {
            Node *t = n->r;
            free(n);
            return t;
        }
        if (!n->r) {
            Node *t = n->l;
            free(n);
            return t;
        }
        Node *t = minimum(n->r);
        n->data = t->data;
        n->r = del(n->r, t->data);
    }
    return n;
}

Node *search(Node *n, int x) {
    while (n && n->data != x)
        n = x < n->data ? n->l : n->r;
    return n;
}

void pre(Node *n) {
    if (n) {
        printf("%d ", n->data);
        pre(n->l);
        pre(n->r);
    }
}

void in(Node *n) {
    if (n) {
        in(n->l);
        printf("%d ", n->data);
        in(n->r);
    }
}

void post(Node *n) {
    if (n) {
        post(n->l);
        post(n->r);
        printf("%d ", n->data);
    }
}

int main() {
    Node *r = NULL;
    int ch, x;
    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Preorder 5.Inorder 6.Postorder 7.Minimum 0.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                scanf("%d", &x);
                r = insert(r, x);
                break;
            case 2:
                scanf("%d", &x);
                r = del(r, x);
                break;
            case 3:
                scanf("%d", &x);
                puts(search(r, x) ? "Found" : "Not found");
                break;
            case 4:
                pre(r);
                puts("");
                break;
            case 5:
                in(r);
                puts("");
                break;
            case 6:
                post(r);
                puts("");
                break;
            case 7: {
                Node *t = minimum(r);
                if (t)
                    printf("Minimum: %d\n", t->data);
                else
                    puts("Empty");
            }
        }
    } while (ch);
    return 0;
}
