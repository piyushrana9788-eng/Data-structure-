#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int data; struct Node *next; } Node;
Node *front=NULL,*rear=NULL;
int isEmpty(void){ return front==NULL; }
int isFull(void){ return 0; } /* Linked queue has no fixed capacity; allocation failure is checked. */
void insert(int x){
    Node *n=(Node*)malloc(sizeof(Node));
    if(!n){ puts("Memory allocation failed"); return; }
    n->data=x; n->next=NULL;
    if(rear) rear->next=n; else front=n;
    rear=n;
}
void deleteQ(void){
    if(isEmpty()){ puts("Queue is empty"); return; }
    Node *t=front; printf("Deleted: %d\n",t->data); front=front->next;
    if(!front) rear=NULL; free(t);
}
void peek(void){ if(isEmpty()) puts("Queue is empty"); else printf("Front: %d\n",front->data); }
int main(void){
    int ch,x;
    do{
        printf("\n1.Insert 2.Delete 3.Peek 4.IsEmpty 5.IsFull 6.Display 0.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Value: "); scanf("%d",&x); insert(x); break;
            case 2: deleteQ(); break;
            case 3: peek(); break;
            case 4: puts(isEmpty()?"Yes, empty":"No, not empty"); break;
            case 5: puts(isFull()?"No fixed capacity (not full)":"No fixed capacity (not full)"); break;
            case 6: for(Node *p=front;p;p=p->next) printf("%d ",p->data); puts(""); break;
        }
    }while(ch!=0);
    while(front) { Node *t=front; front=front->next; free(t); }
    return 0;
}
