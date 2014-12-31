////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-11-26 10:52:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 55
#define INF 0x3f3f3f3f
using namespace std;
 
int n,m,k,ans,aans,cnt,flag;
int pp[maxn];
bool vis[maxn],ok[maxn];
struct Node
{
    int v;
    int next;
} edge[4005];
struct node
{
    int x,cxx;
    int path[maxn];
} cur,now,q[maxn];
 
void addedge(int u,int v)
{
    cnt++;
    edge[cnt].v=v;
    edge[cnt].next=pp[u];
    pp[u]=cnt;
}
bool bfs()
{
    int i,j,u,v;
    int head=0,tail=-1;
    memset(vis,0,sizeof(vis));
    cur.x=1;
    cur.cxx=0;
    vis[1]=1;
    q[++tail]=cur;
    while(head<=tail)
    {
        now=q[head];
        head++;
        u=now.x;
        for(i=pp[u]; i; i=edge[i].next)
        {
            cur=now;
            v=edge[i].v;
            if(ok[v]) continue ;
            if(!vis[v])
            {
                vis[v]=1;
                cur.x=v;
                cur.cxx++;
                cur.path[cur.cxx]=v;
                if(v==n) return true ;
                q[++tail]=cur;
            }
        }
    }
    return false ;
}
void dfs(int num)
{
    if(num>=ans) return ;
    int i,j,u;
    if(bfs())
    {
        node tt=cur;
        if(tt.cxx>k)
        {
            if(ans>num) ans=num;
            return ;
        }
        for(i=1; i<tt.cxx; i++)
        {
            u=tt.path[i];
            ok[u]=1;
            dfs(num+1);
            ok[u]=0;
        }
    }
    else
    {
        if(ans>num) ans=num;
        return ;
    }
}
int main()
{
    int i,j,u,v;
    while(scanf("%d%d%d",&n,&m,&k),n||m||k)
    {
        cnt=0;
        memset(pp,0,sizeof(pp));
        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        ans=INF;
        memset(ok,0,sizeof(ok));
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}