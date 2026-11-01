#include <stdio.h>
#define MAX 10

int data[MAX], top1 = -1, top2 = MAX;

void push1(int x) {
    if (top1 + 1 == top2) printf("Array is full.\n");
    else data[++top1] = x;
}
void push2(int x) {
    if (top1 + 1 == top2) printf("Array is full.\n");
    else data[--top2] = x;
}
void pop1(void) {
    if (top1 == -1) printf("Stack 1 is empty.\n");
    else printf("Popped from stack 1: %d\n", data[top1--]);
}
void pop2(void) {
    if (top2 == MAX) printf("Stack 2 is empty.\n");
    else printf("Popped from stack 2: %d\n", data[top2++]);
}
int main(void)
{
    int choice, value;
    do {
        printf("\n1.Push Stack 1  2.Pop Stack 1  3.Push Stack 2  4.Pop Stack 2  0.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Integer: "); scanf("%d", &value); push1(value); break;
            case 2: pop1(); break;
            case 3: printf("Integer: "); scanf("%d", &value); push2(value); break;
            case 4: pop2(); break;
            case 0: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
