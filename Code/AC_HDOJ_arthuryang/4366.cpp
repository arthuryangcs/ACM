////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-14 11:07:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4366
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:6440KB
//////////////////System Comment End//////////////////
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<queue>
#include<stack>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define oo 1000000007
#define MAXN 50005
#define ll int
using namespace std;
struct node
{
    int a,b,l,id;
} s[MAXN];
struct LINE
{
    int x,y,next;
} line[MAXN];
int Max[MAXN<<2],_next[MAXN];
int hash[1000005],ans[MAXN],dfn[MAXN],Lnum,N,num;
bool cmp(node a,node b)
{
    if (a.b!=b.b) return a.b>b.b;
    return dfn[a.id]>dfn[b.id];
}
void addline(int x,int y)
{
    line[++Lnum].next=_next[x],_next[x]=Lnum;
    line[Lnum].y=y;
}
void dfs(int x)
{
    s[x].l=num;
    for (int k=_next[x]; k; k=line[k].next)
    {
        dfs(line[k].y);
        s[x].l=min(s[x].l,s[line[k].y].l);
    }
    dfn[x]=num;
    num++;
}
void update(int p,int c,int l,int r,int now)
{
    if (l==r)
    {
        Max[now]=c;
        return;
    }
    int mid=l+r>>1;
    if (p<=mid) update(p,c,l,mid,now<<1);
    if (p>mid)  update(p,c,mid+1,r,now<<1|1);
    Max[now]=max(Max[now<<1],Max[now<<1|1]);
}
int query(int L,int R,int l,int r,int now)
{
    if (L<=l && R>=r) return Max[now];
    int mid=l+r>>1,ans=-oo;
    if (L<=mid) ans=max(ans,query(L,R,l,mid,now<<1));
    if (R>mid)  ans=max(ans,query(L,R,mid+1,r,now<<1|1));
    return ans;
}
int main()
{
    int cases,i,x,Q;
    scanf("%d",&cases);
    while (cases--)
    {
        scanf("%d%d",&N,&Q);
        memset(_next,0,sizeof(_next)),Lnum=0;
        for (i=1; i<N; i++)
        {
            scanf("%d%d%d",&x,&s[i].a,&s[i].b);
            hash[s[i].a]=i,s[i].id=i;
            addline(x,i);
        }
        s[0].a=s[0].b=oo;
        s[0].id=0;
        num=0;
        dfs(0);
        sort(s,s+N,cmp);
        memset(Max,-0x3f,sizeof(Max));
        for (i=0; i<N; i++)
        {
            x=query(s[i].l,dfn[s[i].id],0,N-1,1);
            if (x<0) ans[s[i].id]=-1;
            else ans[s[i].id]=hash[x];
            update(dfn[s[i].id],s[i].a,0,N-1,1);
        }
        while (Q--)
        {
            scanf("%d",&x);
            printf("%d\n",ans[x]);
        }
    }
    return 0;
}
