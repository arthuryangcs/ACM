////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-06 15:10:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2476
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[105][105],a[105];
char s[105],t[105];
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(scanf("%s",s+1)>0)
    {
        scanf("%s",t+1);
        s[0]=t[0]=2;
        int len=strlen(s);
        len--;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1;i<=len;i++)
            dp[i][i]=1;
        for(int i=len-1;i>=1;i--)
        {
            for(int j=i+1;j<=len;j++)
            {
                //if(s[i]!=t[i])
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++)
                    if(t[i]==t[k])
                    {
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                    }
            }
        }
        for(int i=1;i<=len;i++)
        {
            a[i]=dp[1][i];
            if(s[i]==t[i])
            {
                if(i==1)
                a[i]=0;
                else
                a[i]=a[i-1];
            }
            else
            for(int j=1;j<i;j++)
            a[i]=min(a[i],a[j]+dp[j+1][i]);

        }
        printf("%d\n",a[len]);

        //printf("%d\n",dp[1][len]);
    }
    return 0;
}
