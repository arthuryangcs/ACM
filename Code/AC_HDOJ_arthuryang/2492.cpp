////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-28 18:32:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2492
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int maxm = 100000;
const int maxn = 20000;
int lb[maxm+100],b[maxm+100],c[maxm+100];
int a[maxn+100];
int g[maxn+100],h[maxn+100];

int calc(int b[],int k)
{
    int i,ans = 0;
    for(i=k;i>0;i-=lb[i]) ans += b[i];
    return ans;
}

void ins(int b[],int k)
{
    int i;
    for(i = k;i<=maxm;i+=lb[i]) b[i]++;
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int cn,n,i;
    __int64 ans;
    scanf("%d",&cn);
    for(i=1;i<=maxm;i++) lb[i]=i&(i^(i-1));
    while(cn--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(i = 0;i<n;i++)
        {
            g[i] = calc (b,a[i]-1);
            ins(b,a[i]);
        }
        for(i=n-1;i>=0;i--)
        {
            h[i] = calc(c,a[i]-1);
            ins(c,a[i]);
        }
        ans = 0;
        for(i = 0;i<n;i++)
            ans += (__int64)g[i] *(n-i-1-h[i]) + (__int64)(i-g[i])*h[i];
        cout<<ans<<endl;
    }
    return 0;
}
