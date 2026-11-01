#include <stdio.h>
#include <string.h>
#define MAX 10000
int main(void){char s[MAX],q[MAX];int count[256]={0},front=0,rear=0;printf("Enter character stream (no spaces): ");scanf("%9999s",s);printf("First non-repeating character at each step:\n");for(int i=0;s[i];i++){unsigned char c=(unsigned char)s[i];count[c]++;q[rear++]=s[i];while(front<rear&&count[(unsigned char)q[front]]>1)front++;if(front==rear)printf("-1 ");else printf("%c ",q[front]);}puts("");return 0;}
