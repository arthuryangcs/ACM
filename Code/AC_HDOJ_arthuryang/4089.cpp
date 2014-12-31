////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-29 15:01:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4089
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:31912KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAXN=2020;
const double eps=1e-5;
double c[MAXN];
double pp[MAXN];
double dp[MAXN][MAXN];
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif
    int n,m,k;
    double p1,p2,p3,p4;
    while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4)!=EOF)
    {
        if(p4<eps)
        {
            printf("0.00000\n");
            continue;
        }
        double p=p2/(1-p1);
        double p41=p4/(1-p1);
        double p31=p3/(1-p1);
        pp[0]=1.0;
        for(int i=1;i<=n;i++) pp[i]=p*pp[i-1];

        dp[1][1]=p41/(1-p);
        c[1]=p41;
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)c[j]=p31*dp[i-1][j-1]+p41;
            for(int j=k+1;j<=i;j++) c[j]=p31*dp[i-1][j-1];
            double tmp=0;
            for(int j=1;j<=i;j++)tmp+=c[j]*pp[i-j];
            //for(int j=k+1;j<=i;j++)tmp+=c[j]*pp[i-j];
            dp[i][i]=tmp/(1-pp[i]);
            dp[i][1]=p*dp[i][i]+c[1];
            for(int j=2;j<i;j++)dp[i][j]=p*dp[i][j-1]+c[j];
        }
        printf("%.5lf\n",dp[n][m]);
    }
    return 0;
}
