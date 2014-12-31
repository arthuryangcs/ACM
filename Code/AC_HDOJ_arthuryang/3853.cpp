////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-29 19:02:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3853
////Problem Title: 
////Run result: Accept
////Run time:2812MS
////Run memory:31924KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXN=1010;
const double eps=1e-5;
double dp[MAXN][MAXN];
double p1[MAXN][MAXN];
double p2[MAXN][MAXN];
double p3[MAXN][MAXN];

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif
    int R,C;
    while(scanf("%d%d",&R,&C)!=EOF)
    {
        for(int i=1;i<=R;i++)
          for(int j=1;j<=C;j++)
            scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j]);
        dp[R][C]=0;
        for(int i=R;i>=1;i--)
          for(int j=C;j>=1;j--)
          {
              if(i==R&&j==C)continue;
              if(fabs(1-p1[i][j])<eps)
                dp[i][j] = 0;
              else
                dp[i][j]=p2[i][j]/(1-p1[i][j])*dp[i][j+1]+p3[i][j]/(1-p1[i][j])*dp[i+1][j]+2/(1-p1[i][j]);
          }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}
