#include <stdio.h>
#define MAX 1000
int main(void){int q[MAX],st[MAX],n,k,top=-1;printf("Queue size: ");scanf("%d",&n);if(n<1||n>MAX)return 0;printf("Enter queue elements: ");for(int i=0;i<n;i++)scanf("%d",&q[i]);printf("Enter k: ");scanf("%d",&k);if(k<0||k>n){puts("Invalid k");return 0;}for(int i=0;i<k;i++)st[++top]=q[i];for(int i=0;i<k;i++)q[i]=st[top--];printf("Result: ");for(int i=0;i<n;i++)printf("%d ",q[i]);puts("");return 0;}
