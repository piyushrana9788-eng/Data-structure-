#include <stdio.h>
#include <string.h>
#define SIZE 100
#define LEN 100
char q[SIZE][LEN];
int front=-1,rear=-1;
int isEmpty(void){ return front==-1; }
int isFull(void){ return (rear+1)%SIZE==front; }
void insert(const char *s){
    if(isFull()){ puts("Queue is full"); return; }
    if(isEmpty()) front=rear=0; else rear=(rear+1)%SIZE;
    snprintf(q[rear],LEN,"%s",s);
}
void deleteQ(void){
    if(isEmpty()){ puts("Queue is empty"); return; }
    printf("Deleted: %s\n",q[front]);
    if(front==rear) front=rear=-1; else front=(front+1)%SIZE;
}
void peek(void){ if(isEmpty()) puts("Queue is empty"); else printf("Front: %s\n",q[front]); }
int main(void){
    int ch; char s[LEN];
    do{
        printf("\n1.Insert 2.Delete 3.Peek 4.IsEmpty 5.IsFull 6.Display 0.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Value: "); getchar(); fgets(s,LEN,stdin); s[strcspn(s,"\n")]=0; insert(s); break;
            case 2: deleteQ(); break;
            case 3: peek(); break;
            case 4: puts(isEmpty()?"Yes, empty":"No, not empty"); break;
            case 5: puts(isFull()?"Yes, full":"No, not full"); break;
            case 6: if(isEmpty()) puts("Queue is empty"); else { int i=front; while(1){ printf("%s ",q[i]); if(i==rear) break; i=(i+1)%SIZE; } puts(""); } break;
        }
    }while(ch!=0);
    return 0;
}
