////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-25 01:03:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:8492KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 1000000
#define INF 0x7fffffff
int dp[MAXN+10];
int mmax[MAXN+10];
int a[MAXN+10];
int m,n;
int big;
int mmmax;
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&m,&n))
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(mmax,0,sizeof(mmax));
        for (int i=1;i<=m;i++)
        {
            mmmax = -INF;
            for(int j=i;j<=n;j++)
            {
                dp[j]=max(dp[j-1]+a[j],mmax[j-1]+a[j]);
                mmax[j-1]=mmmax;
                mmmax=max(mmmax,dp[j]);
            }
        }
        printf("%d\n",mmmax);
    }
    return 0;
}
