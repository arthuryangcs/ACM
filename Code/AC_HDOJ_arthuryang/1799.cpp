////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-03-24 22:37:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1799
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:15772KB
//////////////////System Comment End//////////////////
#include"stdio.h"
int a[2001][2001];
void main()
{
    int i,j,t,m,n;
    for(i=0;i<2001;i++)
    { a[i][0]=a[i][i]=1;
        for(j=1;j<i;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j])%1007;
    }
    scanf("%d",&t);
    while(t--)
    { scanf("%d %d",&m,&n);
        printf("%d\n",a[n][m]);
    }
}