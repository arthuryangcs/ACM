////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-01 12:43:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4336
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:8460KB
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

const int maxn = (1<<20)+10;
const int maxm = 111111;

int n;
double dp[maxn];
double p[22];

void solve()
{
    for(int i = 0;i<n;i++){
        scanf("%lf",&p[i]);
    }
    dp[(1<<n)-1] = 0;
    for(int i = (1<<n)-2; i>=0; i--){
        double  x = 0;
        dp[i] = 1;
        for(int j = 0;j<n;j++){
            if((i&(1<<j))==0){
                dp[i] += p[j]*dp[i|(1<<j)];
                x += p[j];
            }
        }
        //cout<<1/x<<endl;
        dp[i] /= x;
    }
    printf("%.8lf\n",dp[0]);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&n)) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
