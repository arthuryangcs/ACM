////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-27 22:02:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4883
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:296KB
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

int a[24*60];
void slove()
{
    int x,y,l,r,s;
    int ans = 0;
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i = 0; i<n; i++) {
        scanf("%d %d:%d %d:%d",&s,&x,&y,&l,&r);
        a[x*60+y]+=s;
        a[l*60+r]-=s;
    }
    int t = 0;
    for(int i = 0; i<24*60; i++) {
        t += a[i];
        ans = max(ans,t);
    }
    printf("%d\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        while(t--)
            slove();
    }
    return 0;
}
