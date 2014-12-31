////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-12 11:42:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int a[121],b[121];
int main()
{
    int n,t;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[0] = b[0] = 1;
    t=120;
    for (int i=1;i<=120;i++)
    {
        for (int j=0;j<=120;j++)
        {
            for (int k=1;k*i+j<=120 && k<=t;k++)
            {
                b[k*i+j] += a[j];
            }
        }
        for (int j=0;j<=120;j++)
        {
            a[j] = b[j];
        }
    }
    while(scanf("%d",&t)!=EOF)
        printf("%d\n",a[t]);
    return 0;
}
