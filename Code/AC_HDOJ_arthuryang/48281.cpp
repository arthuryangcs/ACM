////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-25 13:03:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4828
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:4144KB
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
const int mo = 1000000007;
int a[1111111];

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int r = exgcd(b,a%b,x,y);
        int t = x;x = y;y = t-a/b*y;
        return r;
    }
}

void init()
{
    int x,y,t;
    a[1] = 1;
    for(int i = 2;i<=1000000;i++)
    {
        a[i] = (ll)a[i-1] *(4*i-2)%mo;
        exgcd(i+1,mo,x,y);
        x = (x+mo)%mo;
        a[i] = (ll)a[i]*x%mo;
    }
}

void slove()
{
    int m;
    scanf("%d",&m);
    printf("%d\n",a[m]);
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    init();
    while(~scanf("%d",&t))
    {
        for(int i = 1;i<=t;i++){
            printf("Case #%d:\n",i);
            slove();
        }
    }
    return 0;
}
