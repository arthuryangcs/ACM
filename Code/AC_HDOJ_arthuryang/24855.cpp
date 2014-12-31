////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-21 14:57:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:288KB
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
const int maxm = 5005;
int n,m,len;
int p[maxn];
int e[maxm];
int next[maxm];

int minlen;
int pp[maxn][maxn];
int last[maxn];
int np[maxn];
bool vis[maxn];
bool v[maxn];

int maxd;
queue<pair<int,int> > q;
void inline ins(int x,int y,int i)
{
    next[i] = p[x];
    e[i] = y;
    p[x] = i;
}

int bfs()
{
    memset(v,0,sizeof(v));
    while(!q.empty()) q.pop();
    q.push(make_pair(1,0));
    last[1] = 0;
    while(!q.empty())
    {
        pair<int,int> pp = q.front();
        q.pop();
        //cout<<pp.first<<pp.second<<endl;
        if(pp.second > len)
            return pp.second;
        for(int i = p[pp.first];i;i = next[i])
        {
            if(vis[e[i]] == false && v[e[i]] == false)
            {
                q.push(make_pair(e[i],pp.second+1));
                last[e[i]] = pp.first;
                if(e[i] == n)
                    return pp.second + 1 ;
                v[e[i]] = true;
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
    for(int j = last[n];last[j];j = last[j])
    {
        pp[deep][nnn++] = j;
        //cout<<j<<" ";
    }
    //cout<<endl;
    for(int i=0;i<nnn;i++)
    {
        //cout<<deep<<pp[deep][i]<<endl;
        if(vis[pp[deep][i]] == true)
            continue;
        vis[pp[deep][i]] = true;
        if(dfs(deep+1))
            return true;
        vis[pp[deep][i]] = false;
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
