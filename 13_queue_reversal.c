#include <stdio.h>
#define MAX 1000
int main(void){int q[MAX],st[MAX],n,top=-1;printf("Queue size: ");scanf("%d",&n);if(n<0||n>MAX)return 0;printf("Enter queue elements: ");for(int i=0;i<n;i++)scanf("%d",&q[i]);for(int i=0;i<n;i++)st[++top]=q[i];for(int i=0;i<n;i++)q[i]=st[top--];printf("Reversed queue: ");for(int i=0;i<n;i++)printf("%d ",q[i]);puts("");return 0;}
