////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-21 20:27:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2486
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:6100KB
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
const int maxn = 1000000;
int fail[maxn];
int ma[maxn];
int n,k;

void slove()
{
    scanf("%d%d",&n,&k);
    if(n<=k)
    {
        printf("lose\n");
        return ;
    }
    for(int i = 1;i<=k+1;i++)
    {
        ma[i] = fail[i] = i;
    }
    ma[k+1] = k + 2;
    int tot = 1;
    int i = k + 1;
    while(n>fail[i])
    {
        fail[i+1] = ma[i] + 1;
        i++;
        //cout<<fail[i]<<endl;
        while(fail[tot]*k < fail[i])
        {
            tot++;
        }
        ma[i] = fail[i] + ma[tot-1];
    }
    if(n == fail[i])
    {
        printf("lose\n");
        return;
    }
    while(n)
    {
        while(n<fail[i])
        {
            i--;
        }
        n -= fail[i];
        tot = fail[i];
    }
    printf("%d\n",tot);
}
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            printf("Case %d: ",i);
            slove();
        }
    }
    return 0;
}
