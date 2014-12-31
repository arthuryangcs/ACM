////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-12 22:51:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4939
////Problem Title: 
////Run result: Accept
////Run time:1718MS
////Run memory:18204KB
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

const int maxn = 1511;
const int maxm = 111111;

ll dp[maxn][maxn];
ll n,x,y,z,t;

void slove()
{
    memset(dp,0,sizeof(dp));
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
    dp[0][0] = 0;
    ll ans = n * x * t;
    for (int i = 1; i <= n; ++i){
        dp[i][0] = dp[i-1][0] + t * (i - 1) * y;
        ans=max(ans,dp[i][0] + t*y*(n - i)*i + x*(n - i)*t);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            if(i-j)
                dp[i][j] = max(dp[i-1][j-1] +(i - j)*y*(t + (j - 1)*z),dp[i-1][j] + (i - 1 - j)*y*(t + j*z));
            else
                dp[i][j] = 0;
            ans = max(ans,dp[i][j] + (n - i)*x*(t + j*z) + (n - i)*(t + j*z)*(i - j)*y);
        }
    }
    printf("%I64d\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t))
    {
        for(int i = 0;i<t;i++){
            printf("Case #%d: ",i+1);
            slove();
        }
    }
    return 0;
}
