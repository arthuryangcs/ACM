////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-25 12:27:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:352KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
using namespace std;
int dp[111111];

int mi(int q,int w,int e)
{
    int t;
    if(q>w)
    {
        t=q,q=w,w=t;
    }
    if(q>e)
    {
        t=q,q=e,e=t;
    }
    return q;
}

int main()
{
    int i;
    int  n,b,a,ans;
    for (i=0;i<150;i++)
    {
        dp[i]=i;
    }
    for (;i<200;i++)
    {
        dp[i]=i-150;
    }
    for (;i<300;i++)
    {
        dp[i]=i-200;
    }
    for (;i<350;i++)
    {
        dp[i]=i-300;
    }
    for (;i<=10000;i++)
    {
        dp[i]=mi(dp[i-150],dp[i-200],dp[i-350]);
    }
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            printf("%d\n",dp[a]);
        }
    }
    return 0;
}
