////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-09-12 17:01:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:937MS
////Run memory:4404KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll(x) (x<<1)
#define rr(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
const int N=100005;

struct node
{
    int l,r;
    int v,t;
    int mid()
    {
        return MID(l,r);
    }
    void fun(int tmp)
    {
        t = tmp;
        v = (r-l+1)*t;
    }
};

struct Segtree
{
    node tree[N*4];
    void build(int l,int r,int ind)
    {
        tree[ind].l=l;
        tree[ind].r=r;
        tree[ind].v =r-l+1;
        tree[ind].t=1;
        if(l!=r)
        {
            int mid=tree[ind].mid();
            build(l,mid,ll(ind));
            build(mid+1,r,rr(ind));
        }
    }
    void update(int st,int ed,int ind,int t)
    {
        int l=tree[ind].l,r=tree[ind].r;
        if(st<=l&&ed>=r)
            tree[ind].fun(t);
        else
        {
            if(tree[ind].t)
            {
                tree[ll(ind)].fun(tree[ind].t);
                tree[rr(ind)].fun(tree[ind].t);
                tree[ind].t=0;
            }
            int mid=tree[ind].mid();
            if(st<=mid) update(st,ed,ll(ind),t);
            if(ed>mid) update(st,ed,rr(ind),t);
            tree[ind].v =tree[ll(ind)].v+tree[rr(ind)].v;
        }
    }
}seg;

int main()
{
    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,b,c;
        scanf("%d%d",&n,&m);
        seg.build(1,n,1);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            seg.update(a,b,1,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",++t_cnt,seg.tree[1].v);
    }

    return 0;
}
