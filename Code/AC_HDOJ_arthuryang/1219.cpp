////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 12:53:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1219
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<string.h>

char a[100001];
int b[200];
int main()
{
    int i;
    while(gets(a))
    {
         for (i=0;i<200;i++)
            b[i]=0;
         for (i=0;a[i]!=0;i++)
         {
             b[(int)a[i]]++;
         }
         for(i='a';i<='z';i++)
            printf("%c:%d\n",i,b[i]);
         printf("\n");
    }
    return 0;
}
