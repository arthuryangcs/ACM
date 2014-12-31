////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-13 23:03:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1814
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:824KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
#define clr(x)memset(x,0,sizeof(x))
#define R 1
#define B 2
#define W 0
const int maxn = 16005;

struct node
{
    int to, next;
}e[100000];
int head[maxn];
int tot;

void add(int s, int t)
{
    e[tot].to = t;
    e[tot].next = head[s];
    head[s] = tot++;
}

int cnt;
int col[maxn];
int ans[maxn];

int n, m;
bool dfs(int u)
{
    if (col[u] == B)
        return false;
    if (col[u] == R)
        return true;
    col[u] = R;
    col[u^1] = B;
    ans[cnt++] = u;
    int i;
    int k;
    for (i=head[u]; i; i=e[i].next)
    {
        k = e[i].to;
        if (!dfs(k))
            return false;
    }
    return true;
}
bool solve()
{
    int i, j;
    memset(col,0,sizeof(col));
    for (i=0; i<n; i++){
        if (col[i])
            continue;
        cnt = 0;
        if (!dfs(i))
        {
            for (j=0; j<cnt; j++)
            {
                col[ans[j]] = W;
                col[ans[j]^1] = W;
            }
            if (!dfs(i^1))
                return false;
        }
    }
    return true;
}
int main()
{
    while (scanf("%d %d",&n, &m)!=EOF)
    {
        n <<= 1;
        int i;
        tot = 1;
        clr(head);
        int a, b;
        while (m--)
        {
            scanf("%d %d",&a, &b);
            a--;
            b--;
            add(a, b^1);
            add(b, a^1);
        }

        if (solve())
        {
            for (i=0; i<n; i++)
                if(col[i] == R)
                    printf("%d\n",i+1);
        }
        else printf("NIE\n");
    }
    return 0;
}