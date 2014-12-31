////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-29 18:16:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4035
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:1340KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 10010;
const int maxm = 111111;
const double eps = 1e-10;

int n;
double e[maxn],k[maxn];
double a[maxn],b[maxn],c[maxn];
vector<int> ma[maxn];

bool dfs(int u,int v)
{
    int len = ma[u].size();
    a[u]=k[u];
    b[u]=(1-k[u]-e[u])/len;
    c[u]=1-k[u]-e[u];
    double tmp=0;
    int t;
    for(int i = 0;i<len;i++){
        t = ma[u][i];
        if(t == v) continue;
        if(!dfs(t,u))
            return false;
        a[u] += (1-e[u]-k[u])/len*a[t];
        c[u] += (1-e[u]-k[u])/len*c[t];
        tmp  += (1-e[u]-k[u])/len*b[t];
    }
    if(fabs(tmp-1)<eps) return false;
    a[u] /= (1-tmp);
    b[u] /= (1-tmp);
    c[u] /= (1-tmp);
    return true;
}

void solve()
{
    scanf("%d",&n);
    int u,v;
    for(int i = 1;i<=n;i++){
        ma[i].clear();
    }
    for(int i = 1;i<n;i++){
        scanf("%d%d",&u,&v);
        ma[u].push_back(v);
        ma[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        scanf("%lf%lf",&k[i],&e[i]);
        k[i]/=100;
        e[i]/=100;
    }
    if(dfs(1,-1) && fabs(1-a[1])>eps){
        printf("%.6lf\n",c[1]/(1-a[1]));
    }
    else printf("impossible\n");
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
            printf("Case %d: ",i);
            solve();
        }
    }
    return 0;
}
