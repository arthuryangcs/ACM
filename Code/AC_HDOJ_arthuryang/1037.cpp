////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-16 12:48:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,c,mi;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        mi=a;
        if(b<mi) mi = b;
        if( c<mi) mi = c;
        if(mi<=168)
            printf("CRASH %d\n",mi);
        else
            printf("NO CRASH\n");
    }
    return 0;
}
