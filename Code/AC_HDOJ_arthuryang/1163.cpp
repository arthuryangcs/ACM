////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 11:15:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1163
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int n,a,b,c;
    while(scanf("%d",&n),n!=0)
    {
        c=b=n%9;
        for (a=1;a<n;a++)
        {
            b=(b*c)%9;
        }
        printf("%d\n",b==0?9:b);
    }
    return 0;
}
