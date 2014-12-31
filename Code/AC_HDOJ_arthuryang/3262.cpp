////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-31 13:23:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3262
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
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
#include<ctype.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n,m,k;
int a[111][111];
bool vis[111][111];

struct aaa
{
    int x,y,n,len,time;
    friend bool operator < (const aaa &a,const aaa &b)
    {
        return a.time<b.time;
    }
}s[111];

bool cmp(const aaa &a,const aaa &b)
{
    return a.n<b.n;
}

void fin(aaa &s)
{
    int k = 0;
    int ans = -1e9;
    s.x = s.y = 0;
    for(int i=1;i<=m-s.len+1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(k=0;k<s.len;k++)
            {
                if(vis[j][k+i])
                    break;
            }
            if(k == s.len && a[j][i] > ans)
            {
                ans = a[j][i];
                s.x = j;
                s.y = i;
            }
        }
    }
    if(ans!=-1e9)
    {
        for(int i=0;i<s.len;i++)
        {
            vis[s.x][s.y+i] = 1;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
        for(int j = 1;j<=m;j++)
        {
            if(!vis[i][j] && a[i][j] >ans)
            {
                ans = a[i][j];
                s.x = i;
                s.y = j;
            }
        }
    if(ans!=-1e9)
    {
        vis[s.x][s.y] = true;
        return ;
    }
}

void slove()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int t,tt;
    for(int i=0;i<k;i++)
    {
        scanf("%d:%d",&t,&tt);
        s[i].time = t*60 + tt;
        //cout<<s[i].time<<endl;
        scanf("%d",&s[i].len);
        s[i].n = i;
    }
    sort(s,s+k);
    for(int i=0;i<k;i++)
    {
        fin(s[i]);
    }
    sort(s,s+k,cmp);
    for(int i=0;i<k;i++)
    {
        if(s[i].x + s[i].y == 0)
            puts("-1");
        else
            printf("%d %d\n",s[i].x,s[i].y);
    }
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d%d%d",&n,&m,&k),n+m+k)
    {
        slove();
    }
    return 0;
}
