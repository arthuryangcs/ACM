////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-13 16:06:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3622
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:956KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 211;
const int maxm = 40005;

int head1[maxn],head2[maxn];
int next1[maxm],next2[maxm];
int edge1[maxm],edge2[maxm];
int num1,num2;
int vis1[maxn],vis2[maxn];
int n;
int cnt;
pair<int,int> e[maxn<<1];
int que[maxn];
int belong[maxn];
int top;

double dis(int x,int y)
{
    return double(e[x].first-e[y].first)*(e[x].first-e[y].first)+double(e[x].second-e[y].second)*(e[x].second-e[y].second);

}

int add(int i,int j)
{
    next1[num1] = head1[i];
    head1[i] = num1;
    edge1[num1] = j;
    num1++;
    next2[num2] = head2[j];
    head2[j] = num2;
    edge2[num2] = i;
    num2++;
}

void init()
{
    num1 = num2 = 1;
    top = 0;
    memset(head1,0,sizeof(head1));
    memset(head2,0,sizeof(head2));
    memset(vis2,0,sizeof(vis2));
    memset(vis1,0,sizeof(vis1));
    memset(belong,0,sizeof(belong));
}

void dfs(int x)
{
    vis1[x] = true;
    for(int i = head1[x]; i; i = next1[i])
    {
        if(!vis1[edge1[i]])
        {
            dfs(edge1[i]);
        }
    }
    que[top++] = x;
}

void dfss(int x)
{
    belong[x] = cnt;
    vis2[x] = true;
    for(int i = head2[x]; i; i = next2[i])
    {
        if(!vis2[edge2[i]])
        {
            dfss(edge2[i]);
        }
    }
}

bool ok()
{
    top = 0;
    for(int i= 2; i<2*n+2; i++)
    {
        if(!vis1[i])
        {
            dfs(i);
        }
    }
    cnt = 1;
    for(int i= 2*n-1; i>=0; i--)
    {
        if(!vis2[que[i]])
        {
            dfss(que[i]);
            cnt++;
        }
    }
    for(int i= 2; i<2*n+2; i+=2)
    {
        if(belong[i]==belong[i+1])
            return false;
    }
    return true;
}

void solve()
{
    for(int i = 2; i<2*n+2;)
    {
        scanf("%d%d",&e[i].first,&e[i].second);
        i++;
        scanf("%d%d",&e[i].first,&e[i].second);
        i++;
    }
    double l = 0,r = 40000.0;
    double mid;
    while(r-l>1e-5)
    {
        mid = (l+r)/2;
        init();
        for(int i = 2; i<2*n+2; i++)
        {
            int t;
            if(i%2==0)t=i+2;
            else t=i+1;
            //mid = 1;
            for(int j=t; j<2*n+2; j++)
                if(dis(i,j)<4*mid*mid)
                {
                    add(i,j^1);
                    add(j,i^1);//注意顺序不能变的
                }

        }
        if(ok())
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    printf("%.2lf\n",(l+r)/2);
}

    int main()
    {
#ifdef ARTHUR_YANG
        freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
        while(~scanf("%d",&n))
        {
            solve();
        }
        return 0;
    }
