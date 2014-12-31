////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-10 15:09:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1823
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:7992KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid,r,rt<<1|1
#define my l,r,rt

const int maxn = 111;
const int maxm = 1111;

int n;
int ma[maxn<<2][maxm<<2];

void sub_insert(int rtt,int a,int L,int l,int r,int rt)
{
    if(l==r-1){
        ma[rtt][rt] = max(ma[rtt][rt],L);
    }
    else{
        int mid = (l+r)>>1;
        if(a<mid) sub_insert(rtt,a,L,lson);
        else sub_insert(rtt,a,L,rson);
        ma[rtt][rt] = max(ma[rtt][rt<<1],ma[rtt][rt<<1|1]);
    }
}

void insert(int h,int a,int L,int l,int r,int rt)
{
    sub_insert(rt,a,L,0,1001,1);
    if(l!=r-1){
        int mid = (l+r)>>1;
        if(h<mid) insert(h,a,L,lson);
        else insert(h,a,L,rson);
    }
}

int sub_query(int rtt,int la,int ra,int l,int r,int rt)
{
    if(la<=l && ra>=r){
        //cout<<rtt<<rt<<ma[rtt][rt]<<endl;
        return ma[rtt][rt];
    }
    else{
        int ans = -1;
        int mid = (l+r)>>1;
        if(la<mid) ans = sub_query(rtt,la,ra,lson);
        if(ra>mid) ans = max(ans,sub_query(rtt,la,ra,rson));
        //cout<<ans<<endl;
        return ans;
    }
}

int query(int lh,int rh,int la,int ra,int l,int r,int rt)
{
    if(lh<=l && rh>=r){
        return sub_query(rt,la,ra,0,1001,1);
    }
    else{
        int mid = (l+r)>>1;
        int ans = -1;
        if(lh<mid) ans = query(lh,rh,la,ra,lson);
        if(rh>mid) ans = max(ans,query(lh,rh,la,ra,rson));
        return ans;
    }
}

void solve()
{
    memset(ma,-1,sizeof(ma));
    char s[11];
    int a,b;
    double x,y;
    for(int i = 0;i<n;i++){
        scanf("%s",s);
        if(s[0] == 'I'){
            scanf("%d%lf%lf",&a,&x,&y);
            insert(a-100,int(x*10+1e-5),int(y*10+1e-5),0,101,1);
        }
        else{
            scanf("%d%d%lf%lf",&a,&b,&x,&y);
            if(a>b) swap(a,b);
            if(x>y) swap(x,y);
            int ans = query(a-100,b-100+1,int(x*10+1e-5),int(y*10+1e-5)+1,0,101,1);
            if(ans == -1){
                puts("-1");
            }
            else{
                printf("%.1lf\n",(double)ans/10.0);
            }

        }
    }
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d",&n),n){
        solve();
    }
}
