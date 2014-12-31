////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-11-09 14:57:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5087
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:684KB
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

int n;
int a[maxn];
int dp[maxn];
int dp2[maxn];
int coun[maxn];

void solve()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    a[n++] = 1e9+1;
    memset(coun,0,sizeof(coun));
    for(int i = 0;i<n;i++){
        dp[i] = 1;
        coun[i] = 1;
        for(int j = 0;j<i;j++){
            if(a[j] < a[i]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    coun[i]=coun[j];
                }
                else if(dp[j] + 1 == dp[i]){
                    coun[i]++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        dp2[i] = 0;
        for(int j = 0;j<i;j++){
            if(a[j] < a[i] && dp2[j] + 1 > dp2[i]){
                dp2[i] = dp2[j] + 1;
            }
        }
        if(dp[i] > dp2[i] && coun[i] > 1){
            dp2[i] = dp[i];
        }
        ans = max(ans,dp2[i]);
    }
    printf("%d\n",ans-1);

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
