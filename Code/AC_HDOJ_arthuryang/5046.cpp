////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-27 19:11:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5046
////Problem Title: 
////Run result: Accept
////Run time:1312MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MaxM = 15*15+10;
const int MaxN = 15*15+10;
const int maxnode = MaxN * MaxM;
const int INF = 0x3f3f3f3f;
typedef long long ll;

struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
    int H[MaxN],S[MaxM];
    int ansd;           //与精确覆盖不同，需要初始化为INF。
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        R[m] = 0; L[0] = m;
        size = m;
        ansd = INF;
        for(int i = 1;i <= n;i++)H[i] = -1;
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void remove(int c)
    {
        for(int i = D[c];i != c;i = D[i])
            L[R[i]] = L[i], R[L[i]] = R[i];
    }
    void resume(int c)
    {
        for(int i = U[c];i != c;i = U[i])
            L[R[i]] = R[L[i]] = i;
    }
    bool v[MaxM];
    int f()
    {
        int ret = 0;
        for(int c = R[0]; c != 0;c = R[c])v[c] = true;
        for(int c = R[0]; c != 0;c = R[c])
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c];i != c;i = D[i])
                    for(int j = R[i];j != i;j = R[j])
                        v[Col[j]] = false;
            }
        return ret;
    }
    void Dance(int d)
    {
        if(d + f() >= ansd)return;
        if(R[0] == 0)
        {
            if(d < ansd)ansd = d;
            return;
        }
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        for(int i = D[c];i != c;i = D[i])
        {
            remove(i);
            for(int j = R[i];j != i;j = R[j])remove(j);
            Dance(d+1);
            for(int j = L[i];j != i;j = L[j])resume(j);
            resume(i);
        }
    }
};

ll n,k;
DLX dd;
pair<ll,ll> ma[100];

inline ll abs(ll &a)
{
    if(a>=0){
        return a;
    }
    else{
        return -a;
    }
}

inline ll dis(int x,int y)
{
    return abs(ma[x].first - ma[y].first) + abs(ma[x].second - ma[y].second);
}

bool ok(ll &len)
{
    dd.init(n,n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(dis(i,j) <= len){
                dd.Link(i+1,j+1);
            }
        }
    }
    dd.Dance(0);
    //cout<<dd.ansd<<endl;
    if(dd.ansd<=k){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    scanf("%I64d%I64d",&n,&k);
    for(int i = 0;i<n;i++){
        scanf("%I64d%I64d",&ma[i].first,&ma[i].second);
    }
    ll l = -1,r = 5e9;
    ll mid;
    while(l<r-1){
        mid = (l+r)>>1;
        if(ok(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    printf("%I64d\n",r);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
            printf("Case #%d: ",i);
            solve();
        }
    }
    return 0;
}
