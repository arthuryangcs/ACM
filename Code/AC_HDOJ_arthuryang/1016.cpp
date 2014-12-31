////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-01 18:04:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int visited[100];
int p[41]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0};
int n;
int ans[100];

void a(int m)
{
    if(m==n)
    {
        if(p[ans[m-1]+ans[0]])
        {
            for (int i=0;i<m-1 ;i++ )
            {
                printf("%d ",ans[i]);
            }
            printf("%d\n",ans[m-1]);
        }
    }
    else
    {
        for (int i=1;i<=n ;i++ )
        {
            if(p[i+ans[m-1]] && visited[i]==0)
            {
                ans[m]=i;
                visited[i]=1;
                a(m+1);
                visited[i]=0;
            }
        }
    }
}

int main()
{
    int num=1;
    ans[0]=1;
    while(~scanf("%d",&n))
    {
        memset(visited,0,sizeof(visited));
        visited[1]=1;
        printf("Case %d:\n",num++);
        a(1);
        printf("\n");
    }
    return 0;
}
