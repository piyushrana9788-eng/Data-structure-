#include <stdio.h>
#define MAX 5

char stack[MAX];
int top = -1;

int isEmpty(void) { return top == -1; }
int isFull(void) { return top == MAX - 1; }

void push(char value)
{
    if (isFull()) printf("Stack is full (overflow).\n");
    else { stack[++top] = value; printf("'%c' pushed.\n", value); }
}
void pop(void)
{
    if (isEmpty()) printf("Stack is empty (underflow).\n");
    else printf("Popped: %c\n", stack[top--]);
}
void peek(void)
{
    if (isEmpty()) printf("Stack is empty.\n");
    else printf("Top character: %c\n", stack[top]);
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
            case 5: printf(isFull() ? "Stack is full.\n" : "Stack is not full.\n"); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
