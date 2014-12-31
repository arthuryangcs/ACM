////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-12 11:35:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int a[60],b[60];
int main()
{
    int n,t;
    scanf("%d",&n);
    while(n--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        a[0] = b[0] = 1;
        for (int i=1;i<=26;i++)
        {
            scanf("%d",&t);
            for (int j=0;j<=50;j++)
            {
                for (int k=1;k*i+j<=50 && k<=t;k++)
                {
                    b[k*i+j] += a[j];
                }
            }
            for (int j=0;j<=50;j++)
            {
                a[j] = b[j];
            }
        }
        int ans=0;
        for (int i=1;i<=50;i++)
            ans += a[i];
        printf("%d\n",ans);
    }
    return 0;
}
