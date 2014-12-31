////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-04-19 19:50:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4540
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:456KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int dp[100][100];
    int map[100][100];
    int i,j,n,k,t,min,x;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<k;j++)
                cin>>map[i][j];
        for(i=0;i<k;i++)
            dp[0][i]=0;
        for(i=1;i<n;i++)
            for(j=0;j<k;j++)
            {
                dp[i][j]=dp[i-1][0]+abs(map[i][j]-map[i-1][0]);
                for (int s=1;s<k;s++)
                {
                    if(dp[i][j]>(dp[i-1][s]+abs(map[i][j]-map[i-1][s])))
                        dp[i][j]=(dp[i-1][s]+abs(map[i][j]-map[i-1][s]));
                }
            }
        min=dp[n-1][0];
        for(i=0;i<k;i++)
            if(dp[n-1][i]<min)
                min=dp[n-1][i];
        cout<<min<<endl;
    }
    return 0;
}
