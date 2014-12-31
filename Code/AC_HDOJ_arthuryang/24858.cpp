////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-21 15:13:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:276KB
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
const int maxn = 55;
const int maxm = 4005;
int n,m,len;
int p[maxn];
int e[maxm];
int next[maxm];
int que[maxn];
int lenn[maxn];

int minlen;
int pp[maxn][maxn];
int last[maxn];
int np[maxn];
bool vis[maxn];
bool v[maxn];

int maxd;
void inline ins(int x,int y,int i)
{
    next[i] = p[x];
    e[i] = y;
    p[x] = i;
}

int bfs()
{
    memset(v,0,sizeof(v));
    int head = 0;
    int fail = 0;
    que[fail] = 1;
    lenn[fail++] = 0;
    last[1] = 0;
    int tq,tl,tt;
    while(head<fail)
    {
        tq = que[head];
        tl = lenn[head++];
        //cout<<pp.first<<pp.second<<endl;
        if(tl > len)
            return tl;
        for(int i = p[tq];i;i = next[i])
        {
            tt = e[i];
            if(vis[tt] == false && v[tt] == false)
            {
                que[fail] = tt;
                lenn[fail++] = tl + 1;
                last[tt] = tq;
                if(tt == n)
                    return tl + 1;
                v[tt] = true;
            }
        }
    }
    return 1e9;
}

bool dfs(int deep)
{
    if(deep == maxd)
    {
        if(bfs()>len)
           return true;
        else
            return false;
    }
    minlen = bfs();
    if(minlen > len)
        return true;
    int nnn = 0;
    int *tt = &pp[deep][nnn];
    for(int j = last[n];last[j];j = last[j])
    {
        *tt = j;
        tt++;
        //cout<<j<<" ";
    }
    nnn = tt-&pp[deep][nnn];
    int t;
    for(int i=0;i<nnn;i++)
    {
        t = pp[deep][i];
        //cout<<deep<<pp[deep][i]<<endl;
        if(vis[t] == true)
            continue;
        vis[t] = true;
        if(dfs(deep+1))
            return true;
        vis[t] = false;
    }
    return false;
    //cout<<endl;
}

void slove()
{
    int x,y;
    memset(p,0,sizeof(p));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        ins(x,y,i);
    }
    for(int i=0;i<=n;i++)
    {
        maxd = i;
        memset(vis,0,sizeof(vis));
        if(dfs(0))
        {
            printf("%d\n",i);
            return ;
        }
    }
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d%d%d",&n,&m,&len),n+m+len)
    {
        //cout<<n<<endl;
        slove();
    }
    return 0;
}
