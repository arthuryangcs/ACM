////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-11-18 13:36:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:524KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define N 155
#define INF 0x7ffffff
#define E 100000

int n,m,k;
int g[N][N],gt[N][N];
int dist1[N],dist2[N];
int map[N][N],path[N],flow[N],start,end;//n为顶点，m为边，map为邻接矩阵
void build()
{
    int x,y,z;
    for (int i = 0;i<=n;i++)
    {
        dist1[i] = dist2[i] = INF;
        for (int j = 0;j<=n;j++)
            g[i][j] = gt[i][j] = 0;
    }
    for (int i=0; i<m;i++)
    {
        scanf("%d %d",&x,&y);
        g[x][y] = gt[y][x] = 1;
    }
}

void bfs(int g[][N],int dis[],int s)
{
    queue<int> a;
    a.push(s);
    for (int i=0;i<N;i++)
        dis[i]=INF;
    dis[s]= 0;
    while(!a.empty())
    {
        int p = a.front();
        a.pop();
        for (int i=1;i<=n;i++)
        {
            if(g[p][i] && dis[i]>dis[p]+1)
            {
                dis[i] =dis[p]+1;
                a.push(i);
            }
        }
    }
}

struct dege
{
    int x;
    int y;
    int next;
}e[E];
int ne;
int head[N];
int cur[N];
int ps[N];
int dep[N];

void add(int x,int y)
{
    e[ne].x = x ;
    e[ne].y = y ;
    e[ne].next = head[x];
    head[x] = ne++;
    e[ne].x = y ;
    e[ne].y = x ;
    e[ne].next = head[y];
    head[y] = ne++;
}

void rebuild()
{
    memset(map,0,sizeof(map));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(g[i][j] && dist1[i] + dist2[j]<k)
            {
                //cout<<i<<j<<dist1[i]<<" "<<dist2[i]<<endl;
                map[2*i-1][2*i]  = 1;
                map[2*i][2*j-1] = INF;
            }

        }
    }
}
queue<int> q;

int bfs()
{
    while(!q.empty())
        q.pop();
    memset(path,-1,sizeof(path));
    for (int i = 0;i<=n;i++) flow[i]=INF;
    q.push(start);
    while(!q.empty() && q.front()!=end)
    {
        int t = q.front();
        q.pop();
        for (int i=1;i<=2*n;i++)
        {
            if(path[i]==-1 && map[t][i]>0 && t!=i)
            {

                flow[i] = min(flow[t],map[t][i]);
                //cout<<flow[end]<<" ";
                path[i] = t;
                q.push(i);
                //--cout<<t<<i<<endl;
            }

        }
       // cout<<t<<endl;
    }
    if(q.empty())
        return -1;
    else
        return flow[end];
}

int kk()
{
    int ans = 0;
    int t,tt;
    while((t = bfs()) != -1)
    {
        ans+=t;
        tt = end;
        //cout<<end;
        while(tt!=start)
        {
            map[tt][path[tt]] += t;
            map[path[tt]][tt] -= t;
            tt = path[tt];
          //  cout<<t<<" "<<tt<<endl;
        }
        //cout<<"sdfs5345345345345345345d"<<endl;
    }
    return ans;
}
int main()
{
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        if (n == 0 && m == 0 && k == 0) return 0;
        if (n < 3) { puts("0"); continue; }
        build();
        bfs(g, dist1, 1);
        bfs(gt, dist2, n);
        rebuild();
        for (int i=0 ;i<=2*n;i++)
           // cout<<dist1[i]<<endl;
       // for (int i=0 ;i<=2*n;i++)
       // {
        //    for (int j=0;j<=2*n;j++)
       //     {
        //        cout<<map[i][j]<<" ";
        //    }
       //     cout<<endl;
       // }
        start = 2;
        end = 2*n-1;
        printf("%d\n",kk());
    }
    return 0;
}
