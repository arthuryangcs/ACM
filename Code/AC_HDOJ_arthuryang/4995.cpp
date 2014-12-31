////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-12 23:02:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4995
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:3860KB
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

const int maxn = 111111;
const int maxm = 111111;

int n;
int m,k;
struct aaa{
    int first;
    double second;
    int id;
    friend bool operator <(const aaa &a,const aaa &b){
        return a.first<b.first;
    }
} a[maxn];
int num[maxn];
int v[maxn];
int id[maxn][2];

void near(int x)
{
    int t = a[x].first;
    int l = x-1,r = x+1;
    for(int i = 0;i<k;i++){
        if(t-a[l].first< a[r].first-t || (t-a[l].first == a[r].first-t) && a[l].id<a[r].id){
            l--;
        }
        else{
            r++;
        }
    }
    id[x][0] = l;
    id[x][1] = r;
}

void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    a[0].first = -2000000000;
    a[n+1].first= 2000000200;
    for(int i = 1;i<=n;i++){
        scanf("%d%lf",&a[i].first,&a[i].second);
        a[i].id = i;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        near(i);
        num[a[i].id] = i;
    }
    int t;
    double ans = 0;
    for(int i = 0;i<m;i++){
        scanf("%d",&t);
        t = num[t];
        //cout<<t<<endl;
        a[t].second = 0;
        for(int i = id[t][0]+1;i<id[t][1];i++) if(i!=t){
            a[t].second += a[i].second/k;
        }
        ans += a[t].second;
    }

    printf("%.6lf\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    scanf("%d",&t);
        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
        }
    return 0;
}