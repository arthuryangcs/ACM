////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-11-20 21:01:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4472
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int dp[1111];
    dp[1]=dp[2]=1;
    for (int i=3;i<=1000;i++)
    {
        int t =0;
        for (int j=1;j<i;j++)
        {
            if((i-j-1)%j==0)
            {
                t+=dp[j];
                t%=1000000007;
            }
        }
        dp[i]=t;
    }
    int num=1;
    int t;
    while(cin>>t)
        cout<<"Case "<<num++<<": "<<dp[t]<<endl;
    return 0;
}
