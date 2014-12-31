////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 18:06:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int f[50]={0,1,1};
    int a,b,i;
    long n;
    while(scanf("%d %d %ld",&a,&b,&n),!(a==0&&b==0&&n==0))
    {
        for(i=3;i<50;i++)
        {
            f[i]=(a*f[i-1]+b*f[i-2])%7;
            if(f[i-1]==1&&f[i]==1)
                break;
        }
        i-=2;
        f[0]=f[i];
        n%=i;
        printf("%d\n",f[n]);
    }
    return 0;
}
