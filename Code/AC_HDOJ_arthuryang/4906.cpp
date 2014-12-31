////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-01 15:40:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4906
////Problem Title: 
////Run result: Accept
////Run time:859MS
////Run memory:4396KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int mod = int(1e9)+7;
int t,n,k,l;
int dp[1<<20];

void add(int &x,int c)
{
    x+=c;
    if(x>=mod)
        x-=mod;
}

void solve()
{
    scanf("%d%d%d",&n,&k,&l);
    int extra = 0;
    if(l>k){
        extra = l-k;
        l = k;
    }
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0;i<n;i++){

        for(int j = (1<<k)-1;j>=0;j--) if(dp[j]){
            int c = dp[j];
            for(int q = 1;q<=l;q++){
                int h = j|((j<<q)&((1<<k)-1))|(1<<(q-1));
                add(dp[h],c);
            }
            add(dp[j],1LL*extra*c%mod);
        }
    }
    int ans = 0;
    for(int i = 0;i<(1<<k);i++) if(i&(1<<k-1)){
        add(ans,dp[i]);
    }
    printf("%d\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 0;i<t;i++) solve();
    }
    return 0;
}
