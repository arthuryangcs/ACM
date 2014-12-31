////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-24 14:18:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2489
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
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

int n,m;
struct edge
{
    int x,y,len;
    friend bool operator <(const edge &a,const edge &b)
    {
        return a.len<b.len;
    }
}e[1000];
int ne;
int mm[22][22];
int len[22];
bool vis[22];
int f[22];
int ans[22];
double mi;
int fa[22];

int getfather(int x)
{
    if(x==fa[x]) return x;
    else return fa[x] = getfather(fa[x]);
}

int sum()
{
    int ans = 0;
    for (int i=0;i<m;i++)
        ans += len[f[i]];
    return ans;
}

int kruskal()
{
    int cnt = m;
    int ans = 0;
    for(int i=0;i<=n;i++) fa[i] = i;
    for(int i=0;i<=ne;i++)
    {
        if(!vis[e[i].x] || !vis[e[i].y])
            continue;
        int t1 = getfather(e[i].x);
        int t2 = getfather(e[i].y);
        if(t1!=t2)
        {
            fa[t1] = t2;
            ans += e[i].len;
            cnt --;
            if(cnt == 1) break;
        }
    }
    return ans;
}

void dfs(int x,int i)
{
    if(x==m)
    {
        double t = (double)kruskal()/sum();
        if(fabs(t-mi)<1e-8)
            return ;
        if(t<mi)
        {
            mi = t;
            for(int i = 0;i<m;i++)
                ans[i] = f[i];
        }
    }
    if(i==1+n)
        return;
    for(;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            f[x] = i;
            dfs(x+1,i+1);
            vis[i] = false;
        }
    }
}

void slove()
{
    ne = 0;
    for(int i=1;i<=n;i++)
        scanf("%d",&len[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&mm[i][j]);
            if(i<j)
            {
                e[ne].x = i;
                e[ne].y = j;
                e[ne++].len = mm[i][j];
            }
        }
    memset(vis,0,sizeof(vis));
    sort(e,e+ne);
    mi = 1e23;
    dfs(0,1);
    printf("%d",ans[0]);
    for(int i=1;i<m;i++)
        printf(" %d",ans[i]);
    printf("\n");
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d%d",&n,&m),n+m)
    {
        slove();
    }
    return 0;
}
