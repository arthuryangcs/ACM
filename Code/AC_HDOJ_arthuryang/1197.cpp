////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 11:47:11
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1197
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int jisuan(int a,int d)
{
    int i,b=0;
    while(a)
    {
        b+=a%d;
        a/=d;
    }
    return b;
}


int main()
{
    int i;
    for (i=2992;i<=9999;i++)
    {
        if(jisuan(i,10)==jisuan(i,16)&&jisuan(i,16)==jisuan(i,12))
            printf("%d\n",i);
    }
    return 0;
}
