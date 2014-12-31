////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 19:43:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

int jisuan(int n)
{
    int sum=1;
    while(n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            n=3*n+1;
        sum++;
    }
    return sum;
}

int main()
{
    int max,i,a,b,c;
    while(scanf("%d %d",&a,&b)!=-1)
    {
        printf("%d %d ",a,b);
        if(a>b)
            c=a,a=b,b=c;
        max=0;
        for (i=a;i<=b;i++)
        {
            c=jisuan(i);
            max=max>c?max:c;
        }
        printf("%d\n",max);
    }
    return 0;
}
