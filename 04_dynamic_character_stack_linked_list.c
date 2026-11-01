#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

int isEmpty(void) { return top == NULL; }
int isFull(void)
{
    Node *test = (Node *)malloc(sizeof(Node));
    if (test == NULL) return 1;
    free(test);
    return 0;
}
void push(char value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) { printf("Stack is full: memory allocation failed.\n"); return; }
    node->data = value; node->next = top; top = node;
    printf("'%c' pushed.\n", value);
}
void pop(void)
{
    Node *temp;
    if (isEmpty()) { printf("Stack is empty (underflow).\n"); return; }
    temp = top; printf("Popped: %c\n", temp->data); top = top->next; free(temp);
}
void peek(void)
{
    if (isEmpty()) printf("Stack is empty.\n");
    else printf("Top character: %c\n", top->data);
}
void clearStack(void)
{
    while (top != NULL) { Node *temp = top; top = top->next; free(temp); }
}
int main(void)
{
    int choice;
    char value;
    do {
        printf("\n1.Push 2.Pop 3.Peek 4.IsEmpty 5.IsFull 0.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter character: "); scanf(" %c", &value); push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: printf(isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n"); break;
            case 5: printf(isFull() ? "Stack is full (allocation failed).\n" : "Stack is not full.\n"); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    clearStack();
    return 0;
}
