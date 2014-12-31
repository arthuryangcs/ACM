////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-16 14:30:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2035
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
#include<cmath>
using namespace std;
int a,b;
int main()
{
    while(scanf("%d%d",&a,&b) && a+b)
    {
        int t=1;
        for (int i=0;i<b;i++)
        {
            t *= a;
            t %= 1000;
        }
        printf("%d\n",t);
    }
    return 0;
}
