////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-17 16:24:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4405
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include <vector>
using namespace std;

const int maxn = 555;

int n,m;
double dp[100111];
int has[100111];


void solve()
{
    int x,y;
    memset(has,-1,sizeof(has));
    for(int i = 0;i<m;i++){
        scanf("%d%d",&x,&y);
        has[x] = y;
    }
    dp[n] = 0;
    for(int i = n-1;i>=0;i--){
        if(has[i]!=-1){
            dp[i] = dp[has[i]];
        }
        else{
            dp[i] = 1;
            for(int j = 1;j<=6 && i+j<=n;j++){
                dp[i] += dp[i+j]/6;
            }
        }
    }
    printf("%.4lf\n",dp[0]);
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d%d",&n,&m),n+m){
        solve();
    }
    return 0;
}
