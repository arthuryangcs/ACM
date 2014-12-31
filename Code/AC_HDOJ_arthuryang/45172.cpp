////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-24 15:15:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4517
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:20912KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
typedef long long int ll;
using namespace std;

char map1[2100][2100];
int  map2[2100][2100];

int n;
int m;
int x,y;
int tmp;
int ans;
int num;
int fx,fy;
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),n+m)
    {
        num=0;
        scanf("%d%d",&x,&y);
        ans=x*y;
        for (i=0;i<n;i++)
        {
            scanf("%s",map1[i]);
        }
        for (i=0;i<=n+1;i++)
        {
            for (j=0;j<=m+1;j++)
            {

                if(i==0 || j==0 || i==n+1 || j==m+1)
                    map2[i][j]=0;
                else
                {
                    if(map1[i-1][j-1]=='*')
                        map2[i][j]=1;
                    else
                        map2[i][j]=0;
                }
                map2[i][j]+=map2[i-1][j]+map2[i][j-1]-map2[i-1][j-1];
            }
        }
        for (i=0;i<=n;i++)
        {
            for (j=0;j<=m;j++)
            {
                if( i+x<=n && j+y<=m)
                {
                   tmp=map2[i][j]+map2[i+x][j+y]-map2[i][j+y]-map2[i+x][j];
                    if(tmp==ans)
                    {
                        num++;
                    }
                }

                if(x!=y && i+y<=n && j+x<=m)
                {
                    tmp=map2[i][j]+map2[i+y][j+x]-map2[i][j+x]-map2[i+y][j];
                    if(tmp==ans)
                    {
                        num++;
                    }
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
