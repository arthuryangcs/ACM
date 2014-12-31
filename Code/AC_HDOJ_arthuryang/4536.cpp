////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-24 15:57:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4536
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int T,n,m,k,tot;

vector<int>zhou[7];

int vis[20];
int da[110][4],a[20];

void dfs(int i)
{
    tot = max(i-1,tot);
    if(i > k) return;
    int tmp[20];
    for(int j = 1; j <= n; j++)
        tmp[j] = a[j];
    a[da[i][1]]-=2;
    if(a[da[i][1]] <= 1) a[da[i][1]] = 1;
    a[da[i][2]]++;
    a[da[i][3]]++;
    for(int j = 0; j < zhou[vis[da[i][2]]].size(); j++){
        int v = zhou[vis[da[i][2]]][j];
        a[v]++;
    }
    for(int j = 0; j < zhou[vis[da[i][3]]].size(); j++){
        int v = zhou[vis[da[i][3]]][j];
        a[v]++;
    }
    int flag = 1;
    for(int j = 1; j <= n; j++)
        if(a[j] > 5) flag = 0;
    if(flag) 
        dfs(i+1);
    for(int j = 1; j <= n; j++)
        a[j] = tmp[j];
    a[da[i][2]]-=2;
    if(a[da[i][2]] <= 1) a[da[i][2]] = 1;
    a[da[i][1]]++;
    a[da[i][3]]++;
    for(int j = 0; j < zhou[vis[da[i][1]]].size(); j++){
        int v = zhou[vis[da[i][1]]][j];
        a[v]++;
    }
    for(int j = 0; j < zhou[vis[da[i][3]]].size(); j++){
        int v = zhou[vis[da[i][3]]][j];
        a[v]++;
    }
    flag = 1;
    for(int j  = 1; j <= n; j++)
        if(a[j] > 5) flag = 0;
    if(flag) dfs(i+1);
    for(int j = 1; j <= n; j++)
        a[j] = tmp[j];
    a[da[i][3]]-=2;
    if(a[da[i][3]] <= 1) a[da[i][3]] = 1;
    a[da[i][1]]++;
    a[da[i][2]]++;
    for(int j = 0; j < zhou[vis[da[i][1]]].size(); j++){
        int v = zhou[vis[da[i][1]]][j];
        a[v]++;
    }
    for(int j = 0; j < zhou[vis[da[i][2]]].size(); j++){
        int v = zhou[vis[da[i][2]]][j];
        a[v]++;
    }
    flag = 1;
    for(int j  = 1; j <= n; j++)
        if(a[j] > 5) flag = 0;
    if(flag) dfs(i+1);
}

int main()
{
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(vis,0,sizeof(vis));
        for(int i = 0; i <= m; i++) 
            zhou[i].clear();
        for(int i = 1; i <= n; i++)
        {
            int v;
            scanf("%d",&v);
            vis[i] = v;
            zhou[v].push_back(i);
        }
        for(int i = 1; i <= n; i++) 
            scanf("%d",&a[i]);
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <= 3; j++)  
            {
                scanf("%d",&da[i][j]);
                da[i][j]++;
            }
        tot = 0;
        dfs(1);
        printf("Case #%d: %d\n",cas,tot);
    }
    return 0;
}
