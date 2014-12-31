////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-10 21:15:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3980
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:328KB
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

const int maxn = 21111;
const int maxm = 111111;

int n,m;
int sg[maxn];
bool vis[maxn];
int mex(int x)
{
    if(x<m) return sg[x] = 0;
    if(sg[x]!=-1) return sg[x];
    memset(vis,0,sizeof(vis));
    for(int i = m;i<=x;i++){
        vis[mex(i-m)^mex(x-i)] = 1;
    }
    for(int i = 0;;i++){
        if(!vis[i]){
            return sg[x] = i;
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    if(n<m){
        puts("abcdxyzk");
        return ;
    }
    n-=m;
    memset(sg,-1,sizeof(sg));
    for(int i = 0;i<=n;i++){
        sg[i] = mex(i);
        //cout<<sg[i]<<endl;
    }
    if(sg[n]){
        puts("abcdxyzk");
    }
    else{
        puts("aekdycoin");
    }
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
            printf("Case #%d: ",i);
            solve();
        }
    }
    return 0;
}
