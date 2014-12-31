////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-26 00:02:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5032
////Problem Title: 
////Run result: Accept
////Run time:3453MS
////Run memory:26168KB
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
struct node
{
    int x,a,b;
    int i;
    ll ans;
    friend bool operator <(const node &a,const node &b)
    {
        if(a.a*b.b == a.b*b.a)
            return a.i<b.i;
        else
            return 1.0*a.b/a.a < 1.0*b.b/b.a;
    }
}a[1111111],b[111111];

bool cmp(const node &a,const node &b)
{
    return a.i<b.i;
}

ll aa[1001];
const int N = 1000;

inline ll lowbit(ll a)
{
    return a&(-a);
}

void add(ll x,ll y)
{
    while(x<=N){
        aa[x] += y;
        x += lowbit(x);
    }
}

ll sum(ll x)
{
    ll ret = 0;
    while(x){
        ret += aa[x];
        x -= lowbit(x);
    }
    return ret;
}

int num;

void solve()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int q;
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].x);
        b[i].i = i;
    }
    sort(b,b+q);
    memset(aa,0,sizeof(aa));
    for(int i = 0,j=0;i<q && j<num;){
        if(1.0*b[i].b/b[i].a >= 1.0*a[j].b/a[j].a){
            add(a[j].a,(a[j].a+x)*(a[j].b+y));
            j++;
        }
        else{
            b[i].ans = sum(b[i].x);
            i++;
            //cout<<"a";
        }
        //cout<<1.0*b[i].b/b[i].a<<" "<<1.0*a[j].b/a[j].a<<endl;
    }
    //cout<<i<<endl;
    sort(b,b+q,cmp);
    for(int i = 0;i<q;i++){
        printf("%I64d\n",b[i].ans);
    }
}

void init()
{
    num = 0;
    for(int i = 1;i<=1000;i++){
        for(int j = 1;j<=1000;j++){
            a[num].a = i;
            a[num].b = j;
            a[num].i = -1;
            num++;
        }
    }
    sort(a,a+num);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    init();
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
            printf("Case #%d:\n",i);
            solve();
        }
    }
    return 0;
}
