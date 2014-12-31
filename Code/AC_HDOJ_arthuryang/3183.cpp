////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-11 20:38:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3183
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
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

const int maxn = 100010;
const int maxm = 111111;

int n,m;
int d[maxn][33];
int prelog[maxn];
int a[maxn];
int b[maxn];
char s[maxn];

inline int min(int a,int b)
{
    return s[a]<=s[b]?a:b;
}

void RMQ_init(int n,char a[])
{
    prelog[1] = 0;
    for(int i =2;i<=n;i++){
        prelog[i] = prelog[i-1];
        if((1<<prelog[i]+1)==i){
            ++prelog[i];
        }
    }
    for(int i = n-1;i>=0;i--){
        d[i][0] = i;
        for(int j = 1;(i+(1<<j)-1)<n;j++){
            d[i][j] = min(d[i][j-1],d[i+(1<<j-1)][j-1]);
        }
    }
}

int query_max(int l,int r)
{
    int len = r-l+1;
    int k = prelog[len];
    return min(d[l][k],d[r-(1<<k)+1][k]);
}
char ans[maxn];
void solve()
{
    int len = strlen(s);
    n = len - n;
    RMQ_init(len,s);
    int q = 0;
    for(int i = 0;i<n;i++){
        q = query_max(q,len-n+i);
        ans[i] = s[q++];
        //cout<<q<<endl;
    }
    int i=0;
    while(i<n && ans[i]=='0') i++;
    if(i==n)
        puts("0");
    else{
        for(;i<n;i++){
            printf("%c",ans[i]);
        }
        puts("");
    }
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%s%d",s,&n)) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
