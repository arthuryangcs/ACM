////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 20:29:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1092
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,sum,i,b[1001];
    scanf("%d",&a);
    while(a!=0)
    {
        for(i=0,sum=0;i<a;i++)
        {
            scanf("%d",&b[i]);
            sum+=b[i];
        }
        printf("%d\n",sum);
        scanf("%d",&a);
    }

    return 0;
}
