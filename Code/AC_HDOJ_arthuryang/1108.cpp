////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 14:35:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,i,n;
    while(~scanf("%d %d",&a,&b))
    {
        n=a>b?b:a;
        for (i=n; i>0 &&(a%i!=0 || b%i!=0);i--);
        n=a*b/i;
        printf("%d\n",n);
    }
    return 0;
}
