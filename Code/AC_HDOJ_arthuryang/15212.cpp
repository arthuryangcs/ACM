////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-13 20:21:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1521
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:376KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
long long int a[222];
long long int b[222];
long long int c[11];

int main()
{
    int n,m,t;
    c[0] = 1;
    for (int i=1;i<=10;i++)
        c[i] = c[i-1] * i;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        a[0] = b[0] = 1;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&t);
            for (int j=1;j<=t;j++)
            {
                for (int k=0;j+k<=m;k++)
                {
                    b[j+k] += a[k] * c[j+k] / c[k] / c[j];
                }
            }
            for (int j=0;j<=m;j++)
                a[j] = b[j];
        }
        cout<<b[m]<<endl;;
    }
    return 0;
}
