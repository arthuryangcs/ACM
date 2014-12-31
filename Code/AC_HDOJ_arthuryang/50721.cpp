////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-10-25 18:58:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5072
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1384KB
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
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef __int64 ll;
const int MAXN = 111111;
bool isprime[MAXN];
int prime[MAXN];
int a[MAXN];
int nu[MAXN];
bool is[MAXN];
int cnt;
int n;

void getprime()
{
    cnt=0;
    memset(isprime,0,sizeof(isprime));
    for(int i=2;i<111111;i++){
        if(!isprime[i])prime[cnt++]=i;
        int res=is[i];
        for(int j=i+i;j<111111;j+=i){
            if(is[j]) res++;
            isprime[j]=1;
        }
        nu[i] = res;
    }
}

void solve()
{
    memset(nu,0,sizeof(nu));
    memset(is,0,sizeof(is));
    scanf("%d",&n);
    int b[20];
    int num;
    int t;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        is[a[i]] = 1;
    }
    getprime();
    ll tmp;
    for(int i = 0;i<n;i++){
        tmp = 0;
        num = 0;
        t = a[i];
        for(int j = 0;prime[j]*prime[j]<=t;j++){
            if(t%prime[j]) continue;
            b[num++] = prime[j];
            t/=prime[j];
            while(t%prime[j]==0) t/=prime[j];
        }
        if(t!=1)
            b[num++] = t;
       // cout<<num<<endl;
        for(int j = 1;j<(1<<num);j++){
            t = 1;
            cnt = -1;
            for(int k = 0;k<num;k++){
                if((1<<k)&j){
                    t *= b[k];
                    cnt *= -1;
                }
            }
            tmp += cnt*nu[t];
        }
        if(tmp)
            ans += (n-tmp)*(tmp-1);
    }
    ans = ll(n)*(n-1)*(n-2)/6 - ans/2;
    printf("%I64d\n",ans);
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
