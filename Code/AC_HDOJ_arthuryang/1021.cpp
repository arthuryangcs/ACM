////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-13 14:23:09
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int a;
    while(~scanf("%d",&a))
    {
        a=a%8;
        if(a==2 || a==6)
            printf("yes\n");
        else
            printf("no\n");
    }
}
