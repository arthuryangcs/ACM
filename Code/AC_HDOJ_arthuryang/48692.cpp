////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-24 14:21:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4869
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:3288KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1000000009;
int n,m;
int a[111111];
ll inv[111111];
ll ba[111111];
ll rba[111111];
void pre()
{
    inv[0] = inv[1] = 1;
    ba[0] = ba[1] = 1;
    rba[0] = rba[1] = 1;
    for(int i = 2;i<111111;i++){
        inv[i] = ((mod-mod/i)*inv[mod%i])%mod;
        ba[i] = (ba[i-1]*i)%mod;
        rba[i] = (rba[i-1]*inv[i])%mod;
    }
}
int C(int n,int k)
{
    return (ba[n]*rba[k]%mod)*rba[n-k]%mod;
}


void solve()
{
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int l = 0,r = 0,ll,rr;
    for(int i = 0;i<n;i++)
    {
        if(a[i]>=l && a[i]<=r)
            ll = !(l%2==a[i]%2);
        else
            ll = min(abs(a[i]-l),abs(a[i]-r));
        rr = min(2*m-l-a[i],m);
        rr = min(r+a[i],rr);
        l = ll;
        r = rr;
        //cout<<l<<" "<<r<<endl;
    }
    long long ans = 0;
    for(int i = l;i<=r;i+=2)
    {
        ans += C(m,i);
        ans %= mod;
    }
    cout<<ans<<endl;
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    pre();
    int t ;
    while(~scanf("%d%d",&n,&m))
        solve();
    return 0;
}
