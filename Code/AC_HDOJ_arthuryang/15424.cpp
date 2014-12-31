////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-07 16:49:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1542
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define maxn 202
#define lson l,mid,rt<<1
#define rson mid,r,rt<<1|1
#define my l,r,rt

int n;
int a[maxn<<2];
double b[maxn<<2];
set<double> se;
struct aaa
{
    double l,r,x;
    int flag;
    friend bool operator <(const aaa &a,const aaa &b)
    {
        return a.x<b.x;
    }
}qu[maxn];
vector<double> all;

void down(int l,int r,int rt)
{
    if(l==r-1) return;
    if(a[rt]){
        b[rt<<1] = all[l+r>>1] - all[l];
        b[rt<<1|1] = all[r] - all[l+r>>1];
    }
}

double insert(int L,int R,int x,int l,int r,int rt)
{
    //down(my);
    if(L<=l && R>=r){
        a[rt] += x;
        b[rt] = all[r] - all[l];
        if(a[rt]==0){
            if(l==r-1){
                b[rt] = 0;
            }
            else{
                b[rt] = b[rt<<1] + b[rt<<1|1];
            }
        }
        return b[rt];
    }
    int mid = (l+r)>>1;
    if(L<mid) insert(L,R,x,lson);
    if(R>mid) insert(L,R,x,rson);
    if(!a[rt])
        b[rt] = b[rt<<1] + b[rt<<1|1];
    return b[rt];
}

double solve()
{
    memset(a,0,sizeof(a));
    for(int i=0;i<maxn<<2;i++){
        b[i]=0;
    }
    se.clear();
    all.clear();
    double x,xx,y,yy;
    int num = 0;
    for (int i = 0;i<n;i++){
        scanf("%lf%lf%lf%lf",&x,&y,&xx,&yy);
        qu[num].flag = 1;
        qu[num].l = y;
        qu[num].r = yy;
        qu[num++].x = x;
        qu[num].flag = -1;
        qu[num].l = y;
        qu[num].r = yy;
        qu[num++].x = xx;
        se.insert(y);
        se.insert(yy);
    }
    sort(qu,qu+num);
    all.insert(all.begin(),se.begin(),se.end());
    sort(all.begin(),all.end());
    double nox = 0,now = 0;
    double ans = 0;
    for(int i = 0 ;i<num;i++){
        ans += (qu[i].x-nox)*now;
        nox = qu[i].x;
        x = lower_bound(all.begin(),all.end(),qu[i].l)-all.begin();
        y = lower_bound(all.begin(),all.end(),qu[i].r)-all.begin();
        //cout<<x<<y<<" ";
        now = insert(x,y,qu[i].flag,0,200,1);
        //cout<<nox<<ans<<endl;
        //cout<<b[1]<<endl;
    }
    return ans;
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t=1;
    while(~scanf("%d",&n)&&n){
        printf("Test case #%d\n",t++);
        printf("Total explored area: %.2lf\n\n",solve());
    }
}
