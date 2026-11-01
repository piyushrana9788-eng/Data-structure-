#include <stdio.h>
#define SIZE 100
int q[SIZE],n=0;
int isEmpty(void){return n==0;} int isFull(void){return n==SIZE;}
/* Larger integer has higher priority. */
void insert(int x){ if(isFull()){puts("Queue is full");return;} int i=n-1; while(i>=0&&q[i]<x){q[i+1]=q[i];i--;} q[i+1]=x;n++; }
void deleteQ(void){if(isEmpty()){puts("Queue is empty");return;} printf("Deleted: %d\n",q[0]); for(int i=1;i<n;i++)q[i-1]=q[i]; n--;}
void peek(void){if(isEmpty())puts("Queue is empty");else printf("Highest priority: %d\n",q[0]);}
int main(void){int ch,x;do{printf("\n1.Insert 2.Delete 3.Peek 4.IsEmpty 5.IsFull 6.Display 0.Exit\nChoice: ");scanf("%d",&ch);switch(ch){case 1:printf("Integer (larger = higher priority): ");scanf("%d",&x);insert(x);break;case 2:deleteQ();break;case 3:peek();break;case 4:puts(isEmpty()?"Yes, empty":"No, not empty");break;case 5:puts(isFull()?"Yes, full":"No, not full");break;case 6:for(int i=0;i<n;i++)printf("%d ",q[i]);puts("");}}while(ch);return 0;}
