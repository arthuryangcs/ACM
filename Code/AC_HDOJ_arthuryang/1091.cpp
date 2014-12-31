////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 20:17:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)
            break;
        printf("%d\n",a+b);
    }
    return 0;
}
