////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-28 18:16:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2491
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:1796KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
int n;
struct aaa
{
    int l,r,ll,rr;
    friend bool operator <(const aaa &a ,const aaa &b)
    {
        return a.ll < b.ll;
    }
}a[111111];

void init(aaa &a)
{
    if(((a.r-a.l)&1)==0)
    {
        a.ll = a.l + ((a.r-a.l)>>1) - 1;
        a.rr = a.ll + 2;
    }
    else
    {
        a.ll = a.l + ((a.r-a.l-1)>>1);
        a.rr = a.ll + 1;
    }
}

void slove()
{
    for (int i=0; i<n;i++ )
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        init(a[i]);
        //cout<<a[i].l<<a[i].r<<a[i].ll<<a[i].rr<<endl;
    }
    sort(a,a+n);
    int en = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(en>a[i].ll)
            break;
        en = max(a[i].rr,en + (a[i].r-a[i].l+2)/2);
    }
    if(i==n)
        puts("YES");
    else
        puts("NO");
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d",&n),n)
    {
        slove();
    }
    return 0;
}
