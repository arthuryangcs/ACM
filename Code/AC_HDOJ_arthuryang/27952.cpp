////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-07 15:29:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:2281MS
////Run memory:5148KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define maxn 222222
#define lson l,mid,rt<<1
#define rson mid,r,rt<<1|1
#define my l,r,rt

int a[maxn<<2];
set<int> se;
pair<int,int> qu[maxn];
vector<int> all;

void push_down(int l,int r,int rt)
{
    if(r==l+1) return ;
    a[rt<<1] = a[rt];
    a[rt<<1|1] = a[rt];
    a[rt] = 0;
}

void up(int rt)
{
    a[rt] = max(a[rt<<1],a[rt<<1|1]);
}

int insert(int c,int l,int r,int rt)
{
    //push_down(my);
    if(a[rt]<c) return -1;
    if(l==r-1){
        a[rt] -= c;
        return l+1;
    }
    int mid = (l+r)>>1;
    int ans;
    if(a[rt<<1]>=c)
        ans = insert(c,lson);
    else
        ans = insert(c,rson);
    up(rt);
    return ans;
}
int x,y,n;
void solve()
{
    int t = n<<2;
    for(int i = 0;i<=t;i++){
        a[i] = y;
    }
    x = min(x,n);
    for(int i = 0;i<n;i++){
        scanf("%d",&t);
        printf("%d\n",insert(t,0,x,1));
    }
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d%d%d",&x,&y,&n)){
        solve();
    }
}
