////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-23 20:39:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4751
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <functional>
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
void fre()
{
    freopen("in.txt","r",stdin);
}
#define MAX 111
int n;
int ma[MAX][MAX];
int l[2][MAX],f[MAX];
int nl[2];


int dfs(int x,int t)
{
    //cout<<x<<endl;
    if(f[x])
        return 1;
    for (int j=0;j<nl[t];j++)
    {
        if(ma[x][l[t][j]] && ma[l[t][j]][x])
            ;
        else
        {
            return 0;
        }
    }
    f[x] = 1;
    l[t][nl[t]++] = x;
    t ^= 1;
    for (int i=1;i<=n;i++)
    {

        if((ma[i][x]==0 || ma[x][i]==0) && f[i] == 0)
        {
            for (int j=0;j<nl[t];j++)
            {
                if(ma[i][l[t][j]] && ma[l[t][j]][i])
                    ;
                else
                {
                    //cout<<i<<l[t][j]<<endl;
                    return 0;
                }
            }
            dfs(i,t);
        }
    }
    return 1;
}

void solve()
{
    nl[0] = nl[1] = 0;
    int t;
    int num = 0;
    memset(f,0,sizeof(f));
    memset(ma,0,sizeof(ma));
    for (int i =1;i<=n;i++)
    {
        while(scanf("%d",&t),t)
        {
            ma[i][t] = 1;
        }
    }
    int i;
    for (i=1;i<=n;i++)
    {
        if(dfs(i,0) == 0)
            break;
    }
    if(i>n)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    //fre();
    while(~scanf("%d",&n))
        solve();
    return 0;
}
