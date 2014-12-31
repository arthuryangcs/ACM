////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 20:38:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1094
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,sum,c,i,b[1001],j;
    while(~scanf("%d",&c))
    {
            for(i=0,sum=0;i<c;i++)
            {
                scanf("%d",&b[i]);
                sum+=b[i];
            }
            printf("%d\n",sum);
    }

    return 0;
}
