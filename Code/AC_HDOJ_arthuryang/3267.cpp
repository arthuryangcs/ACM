////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-03 21:08:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3267
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:2908KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include <cmath>
#include <set>
#include<cstring>
using namespace std;
const int maxn = 66;

int f[maxn];
int s[maxn];
int e[maxn];
int p[maxn];
int ne[maxn];
int num;
set<int> has;
void init(int n)
{
    for(int i = 0;i<=n;i++)
        f[i]=i;
}

int fin_f(int x)
{
    if(f[x]==x) return x;
    else return x=(fin_f(f[x]));
}

bool is_f(int x,int y)
{
    return fin_f(x) == fin_f(y);
}

void set_f(int x,int y)
{
    int a=fin_f(x);
    int b=fin_f(y);
    if(a!=b)
        f[a] = b;
}
int n,m;

void add(int x,int y)
{
    s[num] = x;
    e[num] = y;
    ne[num] = p[x];
    p[x] = num++;
}
bool check(int y)
{
    init(n);
    for(int i =0;i<m;i++)
    {
        if(((1<<i)&y)==0)
        {
           set_f(s[i<<1],e[i<<1]);
        }
    }
    for(int i = 1;i<n;i++)
        if(!is_f(0,i))
        {
            return 1;
        }
    return 0;
}
bool sear(int y,int x)
{
    int t;

    if(check(y)) return 0;
    if(x==((1<<n)-1))
        return 1;
    for(int k = 0;k<n;k++)
    {
        if(!(x&(1<<k))) continue;
        for(int i = p[k];i!=-1;i=ne[i])
        {
            if((x&(1<<e[i]))==0 && (y&(1<<(i/2)))==0)
            {
                if(has.find(y|(1<<(i/2)))!=has.end()) continue;
                has.insert(y|(1<<(i/2)));
                if(sear(y|(1<<(i/2)),x|(1<<e[i]))) return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    num = 0;
    init(n);
    has.clear();
    memset(p,-1,sizeof(p));
    int x,y;
    for(int i = 0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    if(sear(0,1))
        puts("YES");
    else
        puts("NO");
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t=1;
    while(~scanf("%d%d",&n,&m) && m+n!=-2)
    {
        solve();
    }
    return 0;
}
