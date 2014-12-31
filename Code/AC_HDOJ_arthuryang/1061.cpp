////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 10:56:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,c,d[4];
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&b);
        c=b%4;
        b%=10;
        d[1]=b;
        d[2]=(b*b)%10;
        d[3]=(d[2]*b)%10;
        d[0]=(d[3]*b)%10;
        printf("%d\n",d[c]);
    }
    return 0;
}
