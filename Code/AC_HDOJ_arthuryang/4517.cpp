////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-24 15:09:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4517
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:20080KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int map[2010][2010];
char map2[2010][2010];
int n,m,x,y;

int main()
{
    int i,j,ans,temp;
    while(cin>>n>>m && n && m)
    {
        ans=0;
        cin>>x>>y;
        for(i=1;i<=n;i++)
            scanf("%s",map2[i]);
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                if(i==0 || j==0 || i==n+1 || j==m+1)
                {
                    map[i][j]=0;
                }
                else
                {
                    if(map2[i][j-1]=='*')
                    {
                        map[i][j]=1;
                    }
                    else
                    map[i][j]=0;
                }
            }
        }
        for(j=1;j<=m;j++)
        {
            for(i=n;i>=1;i--)
            {
                map[i][j]+=map[i][j-1]+map[i+1][j]-map[i+1][j-1];
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i+x-1<=n && j+y-1<=m)
                {
                    temp=map[i][j+y-1]-map[i][j-1]-map[i+x][j+y-1]+map[i+x][j-1];
                    if(temp==x*y)
                    ans++;
                }
                if(i+y-1<=n && j+x-1<=m)
                {
                    temp=map[i][j+x-1]-map[i][j-1]-map[i+y][j+x-1]+map[i+y][j-1];
                    if(temp==x*y)
                    ans++;
                }
            }
        }
        if(x==y)
        ans=ans/2;
        cout<<ans<<endl;


    }
    return 0;
}