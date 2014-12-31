////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-25 13:25:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:368KB
//////////////////System Comment End//////////////////
#include<iostream>
#include <cstdio>
#include<cstring>
using namespace std;
int dp[1111];
int a[1111];
int v[1111];

int mi(int x,int y)
{
    if(x<y)
        return y;
    else
        return x;
}

int main()
{
    int i,j;
    int t = 0;
    int n,av;
    cin>>t;
    int ma;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&av);
        for (i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
        }
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=1;i<=n;i++)
        {
            for (j=av;j>=a[i];j--)
            {
                dp[j]=mi(dp[j-a[i]]+v[i],dp[j]);
            }
        }
        printf("%d\n",dp[av]);
    }
    return 0;
}
