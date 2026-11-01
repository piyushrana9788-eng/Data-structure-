#include <stdio.h>
#define MAX 1000
int main(void){int n,a[MAX],st[MAX],ans[MAX],top=-1;printf("Array size: ");scanf("%d",&n);if(n<1||n>MAX)return 0;for(int i=0;i<n;i++)scanf("%d",&a[i]);for(int i=n-1;i>=0;i--){while(top>=0&&st[top]>=a[i])top--;ans[i]=(top<0)?-1:st[top];st[++top]=a[i];}puts("Next smaller elements:");for(int i=0;i<n;i++)printf("%d -> %d\n",a[i],ans[i]);return 0;}
