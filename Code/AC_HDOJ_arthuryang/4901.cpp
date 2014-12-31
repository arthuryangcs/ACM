////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-01 14:12:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4901
////Problem Title: 
////Run result: Accept
////Run time:2578MS
////Run memory:18144KB
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
const int maxn = 1<<10;
const int mod = 1000000007;

ll my_xor[1111][maxn];
ll t[2][maxn];
ll my_and[1111][maxn];
int n;
ll a[1111];

void solve()
{
    scanf("%d",&n);
    memset(my_xor,0,sizeof(my_xor));
    memset(t,0,sizeof(t));
    memset(my_and,0,sizeof(my_and));
    for(int i = 0;i<n;i++){
        scanf("%I64d",&a[i]);
    }
    t[0][0] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<1024;j++){
            if(!t[0][j]) continue;
            my_xor[i+1][a[i]^j] += t[0][j];
            my_xor[i+1][a[i]^j] %= mod;

            t[1][a[i]^j] += t[0][j];
            t[1][a[i]^j] %= mod;
            t[1][j] += t[0][j];
            t[1][j] %= mod;
            //cout<<t[0][j]<<" ";
        }
        for(int j = 0;j<1024;j++){
            t[0][j] = t[1][j];
            t[1][j] = 0;
        }
    }
    my_and[n][1023] = 1;
    for(int i = n-1;i>=0;i--){
        for(int j = 0;j<1024;j++){
            if(!my_and[i+1][j]) continue;
            my_and[i][a[i]&j] += my_and[i+1][j];
            my_and[i][a[i]&j] %= mod;
            my_and[i][j] += my_and[i+1][j];
            my_and[i][j] %= mod;
        }
    }
    ll ans = 0;
    //cout<<my_xor[2][3]<<" "<<my_and[2][3]<<endl;
    //cout<<my_xor[3][3]<<" "<<my_and[3][3]<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<1023;j++)
        {
            ans = (ans + my_xor[i][j]*my_and[i][j])%mod;
        }
        ans = (ans + my_xor[i][1023]*((my_and[i][1023]+mod-1)%mod))%mod;
        //ans = (ans + ((my_xor[i][0]+mod-1)%mod)*my_and[i][0])%mod;
    }
    printf("%I64d\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("1005.in","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 0;i<t;i++) solve();
    }
    return 0;
}
