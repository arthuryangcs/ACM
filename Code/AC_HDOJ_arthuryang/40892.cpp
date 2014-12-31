////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-29 15:09:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4089
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:31956KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 111111;
const int maxm = 111111;
const double eps = 1e-6;

int n,m,k;
double p1,p2,p3,p4;
double dp[2022][2022];
double c[2222];
double p[2222];
void solve()
{
    scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
    if(abs(p4)<eps) {
        puts("0.00000");
        return ;
    }
    double p21,p31,p41;
    p21 = p2/(1-p1);
    p31 = p3/(1-p1);
    p41 = p4/(1-p1);
    p[0] = 1.0;
    for(int i = 1;i<=n;i++){
        p[i] = p21*p[i-1];
    }
    dp[1][1] = p41/(1-p21);
    c[1] = p41;
    for(int i = 2;i<=n;i++){
        for(int j=2;j<=k;j++)   c[j]=p31*dp[i-1][j-1]+p41;
        for(int j=k+1;j<=i;j++) c[j]=p31*dp[i-1][j-1];
        double tmp=0;
        for(int j=1;j<=i;j++)tmp+=c[j]*p[i-j];
        dp[i][i]=tmp/(1-p[i]);
        dp[i][1]=p21*dp[i][i]+c[1];
        for(int j=2;j<i;j++)dp[i][j]=p21*dp[i][j-1]+c[j];
    }
    printf("%.5lf\n",dp[n][m]);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d%d%d",&n,&m,&k)) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
