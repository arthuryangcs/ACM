////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-19 15:56:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a[1001],b,i,j,sum;
    while(scanf("%d",&b),b!=0)
    {
        i=b-1;
        sum=0;
        while(b--)
        {
            scanf("%d",&a[b]);
        }
        scanf("%d",&j);
        for(;i>=0;i--)
        {
            if(a[i]==j)
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
