////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-26 13:43:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5036
////Problem Title: 
////Run result: Accept
////Run time:1656MS
////Run memory:428KB
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
#include <bitset>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 111111;
const int maxm = 111111;

int n;
bitset<1001> edge[1001];

void solve()
{
    scanf("%d",&n);
    int m;
    for(int i = 1;i<=n;i++){
        edge[i].reset();
        edge[i][i] = 1;
    }
    int t;
    for(int i = 1;i<=n;i++){
        scanf("%d",&m);
        for(int j = 0;j<m;j++){
            scanf("%d",&t);
            edge[i][t] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(edge[j][i])edge[j]|=edge[i];
        }
    }
    double  ans = 0;
    for(int i = 1;i<=n;i++){
        t = 0;
        for(int j = 1;j<=n;j++){
            if(edge[j][i]){
                t ++;
            }
        }
        ans += 1.0/t;
    }
    printf("%.5lf\n",ans);
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
