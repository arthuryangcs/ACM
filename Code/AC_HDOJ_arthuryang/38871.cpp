////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-02 17:13:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3887
////Problem Title: 
////Run result: Accept
////Run time:609MS
////Run memory:22920KB
//////////////////System Comment End//////////////////
#pragma comment(linker,"/STACK:100000000,100000000")
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1111111
struct sedge
{
    int v;
    int next;
}edge[maxn];
int edgenum,head[maxn],xtime;
int ar[maxn*2],N;
int ans[maxn];

void addedge(int a,int b)
{
    edge[edgenum].v=a;  edge[edgenum].next=head[b];head[b]=edgenum++;
    edge[edgenum].v=b;  edge[edgenum].next=head[a];head[a]=edgenum++;
}

int lowbit(int t)
{
    return t&(-t);
}

void add(int i, int v)
{
    for (; i <= N; ar[i] += v, i += lowbit(i));
}

int sum(int i)
{
    int s = 0;
    for (; i > 0; s += ar[i], i-=lowbit(i));
    return s;
}

void dfs(int x,int fa){
    ans[x]=sum(x-1);
    for(int i=head[x];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v!=fa){
            add(v,1);
            dfs(v,x);
        }
    }
    ans[x]=sum(x-1)-ans[x];
}

int main()
{
    int a,b;
    int n,p;
    while(scanf("%d%d",&n,&p),n+p)
    {
        edgenum=0;
        memset(head,-1,sizeof(head));
        memset(ans,0,sizeof(ans));
        memset(ar,0,sizeof(ar));
        N=2*n;
        for (int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        dfs(p,p);
        for (int i=1;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}
