#include <stdio.h>
#include <string.h>
#define SIZE 100
#define LEN 100
char q[SIZE][LEN]; int front=-1, rear=-1;
int isEmpty(void){ return front==-1; }
int isFull(void){ return rear==SIZE-1; }
void insert(const char *s){
    if(isFull()){ puts("Queue is full"); return; }
    if(isEmpty()) front=0;
    snprintf(q[++rear],LEN,"%s",s);
}
void deleteQ(void){
    if(isEmpty()){ puts("Queue is empty"); return; }
    printf("Deleted: %s\n",q[front]);
    if(front==rear) front=rear=-1; else front++;
}
void peek(void){ if(isEmpty()) puts("Queue is empty"); else printf("Front: %s\n",q[front]); }
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
            case 5: puts(isFull()?"Yes, full":"No, not full"); break;
            case 6: if(isEmpty()) puts("Queue is empty"); else for(int i=front;i<=rear;i++) printf("%s\n",q[i]); break;
        }
    }while(ch!=0);
    return 0;
}
