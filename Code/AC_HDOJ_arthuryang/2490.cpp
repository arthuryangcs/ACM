////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-28 17:22:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2490
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:8304KB
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

const int big = 1000000000;
const int maxn = 105;
const int maxm = 10005;
int n,m,now;
struct aaa
{
    int p,l;
};
int c[maxm],d[maxm],zh[maxm];
aaa sum[maxm];
aaa a[maxn][maxm];
void make(int r)
{
    int i,j,bot,top;
    for(i=0;i<=m;i++) d[i] =-big;
    sum[0].l = 0;
    sum[0].p = 0;
    for (i=1;i<=m ;i++ )
    {
        sum[i].p = sum[i-1].p + a[r][i].p;
        sum[i].l = sum[i-1].l + a[r][i].l;
    }
    bot = 1;
    top = 0;
    for(i=0;i<=m;i++)
    {
        while (bot<=top && sum[i].l-sum[zh[bot]].l>now) bot++;
        while (top>=bot && c[i]-sum[i].p>c[zh[top]]-sum[zh[top]].p) top--;
        top++;
        zh[top] = i;
        d[i] = max(d[i],c[zh[bot]]+sum[i].p-sum[zh[bot]].p);
    }
    sum[m].l = 0;
    sum[m].p = 0;
    for(i = m-1;i>=0;i--)
    {
        sum[i].p = sum[i+1].p + a[r][i+1].p;
        sum[i].l = sum[i+1].l + a[r][i+1].l;
    }
    bot=1;top = 0;
    for(i=m;i>=0;i--)
    {
        while(bot<=top && sum[i].l-sum[zh[bot]].l>now) bot++;
        while(top>=bot && c[i]-sum[i].p>c[zh[top]]-sum[zh[top]].p)top--;
        top++;
        zh[top] = i;
        d[i] = max(d[i],c[zh[bot]]+sum[i].p-sum[zh[bot]].p);
    }
    for(i=0;i<=m;i++) c[i] = d[i];
}
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int i,j,ma;
    while(1)
    {
        scanf("%d%d%d",&n,&m,&now);
        if(n+m+now==0) break;
        n++;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            scanf("%d",&a[i][j].p);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            scanf("%d",&a[i][j].l);
        memset(c,0,sizeof(c));
        for(i=n;i>0;i--)
            make(i);
        ma = 0;
        for(i=0;i<=m;i++)
            ma = max(c[i],ma);
        printf("%d\n",ma);
    }
    return 0;
}
