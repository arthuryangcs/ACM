////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-10-14 16:22:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5001
////Problem Title: 
////Run result: Accept
////Run time:2796MS
////Run memory:5100KB
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

int n,m,d;
double dp[11111][55];
vector<int> ma[55];

double init(int u)
{
    memset(dp,0,sizeof(dp));
    for(int i = 1;i<=n;i++){
        dp[0][i] = 1.0/n;
        if(i == u) dp[0][i] = 0;
    }
    for(int i = 1;i<=d;i++){
        for(int j = 1;j<=n;j++){
            if(j==u) continue;
            for(int k= 0;k<ma[j].size();k++){
                dp[i][ma[j][k]] += dp[i-1][j]/ma[j].size();
            }
        }
    }
    double ans = 0;
    for(int i = 1;i<=n;i++){
        if(i != u)
            ans += dp[d][i];
    }
    return ans;
}

void solve()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i = 1;i<=n;i++){
        ma[i].clear();
    }
    int x,y;
    for(int i  =0 ;i<m;i++){
        scanf("%d%d",&x,&y);
        ma[x].push_back(y);
        ma[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        printf("%.16lf\n",init(i));
    }
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
        }
    }
    return 0;
}
