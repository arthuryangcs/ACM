////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-29 23:07:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4893
////Problem Title: 
////Run result: Accept
////Run time:1796MS
////Run memory:6276KB
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
#define lson l,mid,rt<<1
#define rson mid,r,rt<<1|1
#define my l,r,rt

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 111111;
const int maxm = 111111;

bool isfib[maxn<<2];
ll f[100];
int num;
ll fib[maxn<<2];
ll sum[maxn<<2];
ll nearest(ll x)
{
    if(x<=1) return 1;
    int s= upper_bound(f,f+num,x) - f;
    //cout<<(f[s]-x<x-f[s-1]?f[s]:f[s-1])<<endl;
    return f[s]-x<x-f[s-1]?f[s]:f[s-1];
}

void down(ll l,ll r,ll rt)
{
    if(r-l==1) return ;
    if(isfib[rt]){
        sum[rt<<1] = fib[rt<<1];
        sum[rt<<1|1] = fib[rt<<1|1];
        isfib[rt] = false;
        isfib[rt<<1] = isfib[rt<<1|1] = true;
    }
}

void up(ll rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    fib[rt] = fib[rt<<1] + fib[rt<<1|1];
}

void change(ll x,ll c,ll l,ll r,ll rt)
{
    down(my);
    if(r-l==1 && l==x){
        sum[rt] += c;
        fib[rt] = nearest(sum[rt]);
        return ;
    }
    ll mid = (l+r)>>1;
    if(x<mid) change(x,c,lson);
    if(x>=mid) change(x,c,rson);
    up(rt);
}

void update(ll L,ll R,ll l,ll r,ll rt)
{
    down(my);
    if((L<=l && R>=r) || isfib[rt])
    {
        isfib[rt] = true;
        sum[rt] = fib[rt];
        return ;
    }

    ll mid = (l+r)>>1;
    if(L<mid) update(L,R,lson);
    if(R>mid) update(L,R,rson);
    up(rt);
}

ll quary(ll L,ll R,ll l,ll r,ll rt)
{
    if(L<=l && R>=r){
        return sum[rt];
    }
    down(my);
    ll ret = 0;
    ll mid = (l+r)>>1;
    if(L<mid) ret += quary(L,R,lson);
    if(R>mid) ret += quary(L,R,rson);
    return ret;
}

ll n,q;

void debug()
{
//    for(int i  = 1;i<=n<<2;i++){
//        printf("%d ",i);
//    }
//    puts("");
    for(int i  = 1;i<=n<<2;i++){
        printf("%I64d ",sum[i]);
    }
    puts("");
    for(int i  = 1;i<=n<<2;i++){
        printf("%I64d ",fib[i]);
    }
    puts("");
    puts("");
}

void init(ll l, ll r,ll rt)
{
    if(r-l==1){
        fib[rt] = 1;
        return ;
    }
    ll mid = (l+r)>>1;
    fib[rt] = r-l;
    init(rson);
    init(lson);
}

void slove()
{
    ll x,y,z;
    memset(sum,0,sizeof(sum));
    ll t = (n+1)<<2;
    init(1,n+1,1);
    memset(isfib,0,sizeof(isfib));
    for(int i = 0;i<q;i++){
        scanf("%I64d%I64d%I64d",&z,&x,&y);
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(z==1){
            change(x,y,1,n+1,1);
        }
        else if(z==2){
            printf("%I64d\n",quary(x,y+1,1,n+1,1));
        }
        else{
            update(x,y+1,1,n+1,1);
        }
        //debug();
    }
}

int main()
{
#ifdef ARTHUR_YANG
freopen("1007.in","r",stdin);
#endif
    int t;
    f[0] = f[1] = 1;
    for(int i = 2;;i++){
        f[i] = f[i-2] + f[i-1];
        if(f[i]>=1e17){
            num = i+1;
            break;
        }
    }
    while(~scanf("%I64d%I64d",&n,&q))
    {
        slove();
    }
    return 0;
}
