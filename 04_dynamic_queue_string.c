#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
typedef struct Node { char data[LEN]; struct Node *next; } Node;
Node *front=NULL,*rear=NULL;
int isEmpty(void){ return front==NULL; }
int isFull(void){ return 0; } /* No fixed capacity; malloc failure is checked. */
void insert(const char *s){
    Node *n=(Node*)malloc(sizeof(Node));
    if(!n){ puts("Memory allocation failed"); return; }
    snprintf(n->data,LEN,"%s",s); n->next=NULL;
    if(rear) rear->next=n; else front=n; rear=n;
}
void deleteQ(void){
    if(isEmpty()){ puts("Queue is empty"); return; }
    Node *t=front; printf("Deleted: %s\n",t->data); front=front->next;
    if(!front) rear=NULL; free(t);
}
void peek(void){ if(isEmpty()) puts("Queue is empty"); else printf("Front: %s\n",front->data); }
int main(void){
    int ch; char s[LEN];
    do{
        printf("\n1.Insert 2.Delete 3.Peek 4.IsEmpty 5.IsFull 6.Display 0.Exit\nChoice: ");
        scanf("%d",&ch); getchar();
        switch(ch){
            case 1: printf("String: "); fgets(s,LEN,stdin); s[strcspn(s,"\n")]=0; insert(s); break;
            case 2: deleteQ(); break;
            case 3: peek(); break;
            case 4: puts(isEmpty()?"Yes, empty":"No, not empty"); break;
            case 5: puts("Dynamic queue has no fixed capacity; it is full only if memory allocation fails."); break;
            case 6: for(Node *p=front;p;p=p->next) puts(p->data); break;
        }
    }while(ch!=0);
    while(front){ Node *t=front; front=front->next; free(t); }
    return 0;
}
