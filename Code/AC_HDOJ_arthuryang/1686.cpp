////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-18 01:11:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1686
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int n,m;
char a[1000005];
char b[10005];
int p[10005];

void Pre()
{
    int i,j;
    j=-1;
    p[0]=-1;
    for (i=1;i<m;i++)
    {
        while(j>=0 && b[j+1]!=b[i]) j=p[j];
        if (b[j+1]==b[i]) j++;
        p[i]=j;
    }
}

int Solve()
{
    int i,j,cnt;
    cnt=0;
    j=-1;
    for (i=0;i<n;i++)
    {
        while(j>=0 && b[j+1]!=a[i]) j=p[j];
        if (b[j+1]==a[i]) j++;
        if (j==m-1) cnt++;
    }
    return cnt;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",b);
        scanf("%s",a);
        n=strlen(a);
        m=strlen(b);
        Pre();
        printf("%d\n",Solve());
    }
    return 0;
}
