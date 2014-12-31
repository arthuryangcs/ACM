////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-25 23:36:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5032
////Problem Title: 
////Run result: Accept
////Run time:2640MS
////Run memory:19136KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define lowbit(x) (x&(-x))
#define maxn 1005

using namespace std;
typedef long long ll;
int A,B;
struct node
{
    int r,c;
    double p;
    node(){}
    node(int _r,int _c,double _p):r(_r),c(_c),p(_p){}
    bool operator < (const node &cmp)const
    {
        return p<cmp.p;
    }
};
vector <node> cq;
struct line
{
    int x,id;
    ll ans;
    double p;
    line(){}
    line(int _x,double _p):x(_x),p(_p){}
    bool operator < (const line &cmp)const
    {
        return p<cmp.p;
    }
};
vector <line> scline;
ll bit[1005];
bool cmp_id(line a,line b)
{
    return a.id<b.id;
}
void update(int pos,ll val)
{
    for(int x=pos;x<=1000;x+=lowbit(x))
        bit[x]+=val;
}
ll query(int l,int r)
{
    ll res=0;
    for(int x=r;x>=1;x-=lowbit(x))res+=bit[x];
    ll ret=0;
    for(int x=l-1;x>=1;x-=lowbit(x))ret+=bit[x];
    return res-ret;
}

int main()
{
    int T,cas=1;

    cq.clear();

    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            cq.push_back(node(i,j,1.0*i/j));
        }
    }

    sort(cq.begin(),cq.end());


    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&A,&B);

        scline.clear();

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            int x,a,b;
            scanf("%d%d%d",&a,&b,&x);
            scline.push_back(line(x,1.0*b/a));
            scline[i].id=i;
        }

        memset(bit,0,sizeof bit);

        sort(scline.begin(),scline.end());
        int pos=0;
        for(int i=0;i<n;i++)
        {
            while(cq[pos].p<=scline[i].p)
            {
                update(cq[pos].c,(ll)(cq[pos].r+B)*(cq[pos].c+A));
                pos++;
            }
            scline[i].ans=query(1,scline[i].x);
        }

        sort(scline.begin(),scline.end(),cmp_id);

        printf("Case #%d:\n",cas++);
        for(int i=0;i<n;i++)
            printf("%I64d\n",scline[i].ans);
    }
    return 0;
}
