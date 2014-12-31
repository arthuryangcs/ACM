////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-11 19:40:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1806
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:14328KB
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

void RMQ_init(int n,int a[])
{
    prelog[1] = 0;
    for(int i =2;i<=n;i++){
        prelog[i] = prelog[i-1];
        if((1<<prelog[i]+1)==i){
            ++prelog[i];
        }
    }
    for(int i = n-1;i>=0;i--){
        d[i][0] = a[i+1];
        for(int j = 1;(i+(1<<j)-1)<n;j++){
            d[i][j] = max(d[i][j-1],d[i+(1<<j-1)][j-1]);
        }
    }
}

int query_max(int l,int r)
{
    int len = r-l+1;
    int k = prelog[len];
    return max(d[l][k],d[r-(1<<k)+1][k]);
}

int fin(int l,int r)
{
    int mid;
    r++;
    int k = a[l];
    while(l<r-1){
        mid = (l+r)>>1;
        if(a[mid]>k){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return l;
}

void solve()
{
    scanf("%d",&m);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i+1]);
    }
    int t = 1;
    b[1] = t;
    for(int i = 2;i<=n;i++){
        if(a[i]==a[i-1]){
            t++;
        }
        else{
            t = 1;
        }
        b[i] = t;
    }
    RMQ_init(n,b);
    int l,r;
    for(int i = 0;i<m;i++){
        scanf("%d%d",&l,&r);
        t = fin(l,r);
        //cout<<t<<endl;
        if(t == r){
            printf("%d\n",t-l+1);
        }
        else{
            printf("%d\n",max(query_max(t,r-1),t-l+1));
        }
    }
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&n),n) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
