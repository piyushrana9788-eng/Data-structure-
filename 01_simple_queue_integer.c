#include <stdio.h>
#define SIZE 100
int q[SIZE], front = -1, rear = -1;
int isEmpty(void) { return front == -1; }
int isFull(void) { return rear == SIZE - 1; }
void insert(int x) {
    if (isFull()) { printf("Queue is full\n"); return; }
    if (isEmpty()) front = 0;
    q[++rear] = x;
}
void deleteQ(void) {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Deleted: %d\n", q[front]);
    if (front == rear) front = rear = -1; else front++;
}
void peek(void) {
    if (isEmpty()) printf("Queue is empty\n");
    else printf("Front: %d\n", q[front]);
}
int main(void) {
    int ch, x;
    do {
        printf("\n1.Insert 2.Delete 3.Peek 4.IsEmpty 5.IsFull 6.Display 0.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) return 0;
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); insert(x); break;
            case 2: deleteQ(); break;
            case 3: peek(); break;
            case 4: printf(isEmpty() ? "Yes, empty\n" : "No, not empty\n"); break;
            case 5: printf(isFull() ? "Yes, full\n" : "No, not full\n"); break;
            case 6: if (isEmpty()) puts("Queue is empty"); else { for (int i=front;i<=rear;i++) printf("%d ",q[i]); puts(""); } break;
        }
    } while (ch != 0);
    return 0;
}
