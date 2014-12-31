////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-10 20:00:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1848
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
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

const int maxn = 11111;
const int maxm = 111111;

int n;
bool vis[maxn];
int sg[maxn];
int a,b,c;

void init()
{
    sg[0] = 0;
    int t;
    for(int i = 1;i<=1000;i++){
        memset(vis,0,sizeof(vis));
        for(int j = 1,k=1;i-j>=0;){
            vis[sg[i-j]] = 1;
            t = k;
            k += j;
            j = t;
        }
        for(int j = 0;;j++){
            if(!vis[j]){
                sg[i] = j;
                break;
            }
        }
    }
}

void solve()
{
    if((sg[a]^sg[b]^sg[c])!=0){
        puts("Fibo");
    }
    else{
        puts("Nacci");
    }
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    init();
    int t;
    while(~scanf("%d%d%d",&a,&b,&c),a+b+c) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
