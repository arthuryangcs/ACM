////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-30 14:13:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3260
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:804KB
//////////////////System Comment End//////////////////
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
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

const int big = 1e9;

int n,k,m;
char s[111111111];
int g[1111];
int ma[1111][1111];
bool f[1111][1111];

bool get(int &x)
{
    while(1)
    {
        if(s[x] == '$')
        {
            x++;
            return 1;
        }
        else if(s[x] == 'v')
        {
            x++;
            return 0;
        }
        else
        {
            x++;
        }
    }
}

int getint(int &x)
{
    int ans = 0,k = 1;
    if(s[x] == '-')
    {
        k = -1;
        x++;
    }
    while(isdigit(s[x]))
    {
        ans = ans*10 + s[x++] - '0';
    }
    ans *= k;
    return ans;
}

void dfs(int money,int x,int y,int v,int t)
{
    //cout<<money<<" "<<x<<" "<<y<<" "<<v<<" "<<t<<endl;
    if(y>=m)
        return ;
    x = min(n-1,x);
    if(x <= 0 && t)
    {
        g[y] = max(g[y],money);
        return ;
    }
    if(t == k)
        return ;
    if(f[x][y] == 1)
        money += ma[x][y];
    else
        v += ma[x][y];
    if(x == 0) v = 0;
    dfs(money,x+v,  y+1,v  ,t+1);
    dfs(money,x+v+1,y+1,v+1,t+1);
    dfs(money,x+v-1,y+1,v-1,t+1);
}

void slove()
{
    int x;
    for(int i=0;i<m;i++)
        g[i] = -big;
    for(int i=0;i<n;i++)
    {
        gets(s);
        x = 0;
        for(int j=0;j<m;j++)
        {
            f[i][j] = get(x);
            ma[i][j] = getint(x);
            //cout<<ma[i][j]<<" ";
        }
       // cout<<endl;
    }
    g[0] = 0;
    for(int i=0;i<m-1;i++)
    {
        if(-big != g[i])
            dfs(g[i],0,i,0,0);
        //cout<<g[i]<<endl;
    }
    printf("%d\n",g[m-1]+(f[0][m-1]?ma[0][m-1]:0));
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d%d%d ",&n,&m,&k),n+m+k)
    {
        slove();
    }
    return 0;
}
