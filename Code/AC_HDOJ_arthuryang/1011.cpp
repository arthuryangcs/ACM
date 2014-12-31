////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-06-28 20:57:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1011
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int nMax = 105;
int map[nMax][nMax];
int d[nMax][nMax];
int visit[nMax];

 int ma(int a,int b)
 {
     return a>b?a:b;
 }

struct Room
{
	int bugs, brains;
}room[nMax];
int N, M;

int dp(int u)
{
    visit[u]=1;
    int i,j,k;
    int r = (room[u].bugs + 19) / 20;
    for(i = M; i >= r; i --)
        d[u][i] = room[u].brains;
    for (i=1;i<=N ;i++ )
    {
        if(map[u][i] && !visit[i])
        {
            dp(i);
            for (j=M;j>=r;j--)
            {
                for (k=1;k<=j-r ;k++ )
                {
                    d[u][j]=ma(d[u][j],d[u][j-k]+d[i][k]);
                }
            }
        }
    }
}

int main()
{
    int i,j;
    int a,b;
    while(scanf("%d %d",&N,&M),N+M!=-2)
    {
        memset(map, 0, sizeof(map));
        for (i=1;i<=N ;i++ )
        {
            scanf("%d %d",&room[i].bugs,&room[i].brains);
        }
        for (i=1;i<N ;i++ )
        {
            scanf("%d %d",&a,&b);
            map[a][b]=map[b][a]=1;
        }
        if(M==0)
            printf("0\n");
        else
        {
            memset(d, 0, sizeof(d));
            memset(visit, 0, sizeof(visit));
            dp(1);
            printf("%d\n",d[1][M]);
        }
    }
    return 0;
}

