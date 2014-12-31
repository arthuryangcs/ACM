////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 16:51:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1194
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d %d",&a,&b);
        if(a>=b&&(a-b)%2==0)
            printf("%d %d\n",(a+b)/2,(a-b)/2);
        else
                printf("impossible\n");
    }
    return 0;
}
