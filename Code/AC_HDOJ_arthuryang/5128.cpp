////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-12-03 21:21:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5128
////Problem Title: 
////Run result: Accept
////Run time:0MS
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

const int maxn = 111111;
const int maxm = 111111;
bool g[222][222];

int n;
struct node
{
    int x,y;
}a[33];

inline int judge(int x,int y,int xx,int yy,int x2,int y2,int xx2,int yy2)
{
    if(x2>xx || y2>yy || xx2<x || yy2<y) return (xx-x)*(yy-y)+(xx2-x2)*(yy2-y2);
    if(x2>x && xx2<xx && y2>y && yy2<yy) return (xx-x)*(yy-y);
    return 0;
}

void solve()
{
    memset(g,0,sizeof(g));
    int x,y,xx,yy;
    int x2,y2,xx2,yy2;
    for(int i = 0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        g[a[i].x][a[i].y] = 1;
    }
    int ans = 0;
    for(int i =  0;i<n;i++){
        for(int j = i+1;j<=n;j++){
            x = min(a[i].x,a[j].x);
            xx = max(a[i].x,a[j].x);
            y = min(a[i].y,a[j].y);
            yy = max(a[i].y,a[j].y);
            if(!g[x][yy] || !g[xx][y] || !g[x][y] || !g[xx][yy]) continue;
            if(x==xx || y==yy) continue;
            for(int q = 0;q<n;q++){
                for(int w = q+1;w<n;w++){
                    x2 = min(a[q].x,a[w].x);
                    xx2 = max(a[q].x,a[w].x);
                    y2 = min(a[q].y,a[w].y);
                    yy2 = max(a[q].y,a[w].y);
                    if(!g[x2][yy2] || !g[xx2][y2] || !g[x2][y2] || !g[xx2][yy2]) continue;
                    if(x2==xx2 || y2==yy2) continue;
                    ans = max(ans,judge(x,y,xx,yy,x2,y2,xx2,yy2));
                }
            }
        }
    }
    if(ans)
        printf("%d\n",ans);
    else
        puts("imp");
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(scanf("%d",&n),n) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
