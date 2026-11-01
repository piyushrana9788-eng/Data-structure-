#include <stdio.h>
#include <string.h>
#define SIZE 100
#define LEN 100
int q[SIZE];
int front=-1,rear=-1;
int isEmpty(void){return front==-1;}
int isFull(void){return (front==0&&rear==SIZE-1)||(front==rear+1);}
void insertFront(int x){if(isFull()){puts("Deque is full");return;}if(isEmpty())front=rear=0;else if(front==0)front=SIZE-1;else front--;q[front]=x;}
void insertRear(int x){if(isFull()){puts("Deque is full");return;}if(isEmpty())front=rear=0;else if(rear==SIZE-1)rear=0;else rear++;q[rear]=x;}
void deleteFront(void){if(isEmpty()){puts("Deque is empty");return;}printf("Deleted: %d\n",q[front]);if(front==rear)front=rear=-1;else if(front==SIZE-1)front=0;else front++;}
void deleteRear(void){if(isEmpty()){puts("Deque is empty");return;}printf("Deleted: %d\n",q[rear]);if(front==rear)front=rear=-1;else if(rear==0)rear=SIZE-1;else rear--;}
void peek(void){if(isEmpty())puts("Deque is empty");else printf("Front: %d, Rear: %d\n",q[front],q[rear]);}
int main(void){int ch;int x;do{printf("\n1.InsertFront 2.InsertRear 3.DeleteFront 4.DeleteRear 5.Peek 6.IsEmpty 7.IsFull 8.Display 0.Exit\nChoice: ");scanf("%d",&ch);switch(ch){case 1:printf("Value: ");scanf("%d",&x);insertFront(x);break;case 2:printf("Value: ");scanf("%d",&x);insertRear(x);break;case 3:deleteFront();break;case 4:deleteRear();break;case 5:peek();break;case 6:puts(isEmpty()?"Yes, empty":"No, not empty");break;case 7:puts(isFull()?"Yes, full":"No, not full");break;case 8:if(!isEmpty()){int i=front;while(1){printf("%d ",q[i]);if(i==rear)break;i=(i+1)%SIZE;}}puts("");break;}}while(ch);return 0;}
