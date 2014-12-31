////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-11-09 15:50:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
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
int m = 1;

void update(int x,int val)
{
    if(dp[x] > val){
        dp2[x] = dp[x];
        dp[x] = val;
    }
    else if(dp2[x] > val){
        dp2[x] = val;
    }
}

void solve()
{
    scanf("%d",&n);
    int t;
    dp[0] = 0;
    dp2[0] = 1e9+1;
    m = 1;
    int l ,r,mid;
    for(int i = 0;i<n;i++){
        scanf("%d",&t);
        l = 0;
        r = m;
        while(l<r-1){
            mid = (l+r)/2;
            if(dp[mid] >= t){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        if(r == m){
            dp[m++] = 1e9+1;
        }
        if(dp2[r-1] < t)update(r,t);
        update(r,t);
    }
    if(dp2[m-1] == int(1e9+1))
        m--;
    printf("%d\n",m-1);
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
