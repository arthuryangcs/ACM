////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-16 10:54:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1014
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:596KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int a[1000001];
int main()
{
    int b,mod,step,i,j;
    while(~scanf("%d %d",&step,&mod))
    {
        a[0]=0;
        for (i=1;a[i]=(a[i-1]+step)%mod;i++);
        if(i==mod)
            printf("%10d%10d    Good Choice\n\n",step,mod);
        else
            printf("%10d%10d    Bad Choice\n\n",step,mod);
    }
    return 0;
}
