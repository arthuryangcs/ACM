////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 15:04:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int jc(int n)
{
    int t = 1;
    for (int i=2;i<=n ;i++ )
        t *= i;
    return t;
}

int n;
int a,b;
char s[3];

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='A')
            printf("%d\n",jc(a)/jc(a-b));
        else
            printf("%d\n",jc(a)/jc(b)/jc(a-b));
    }
    return 0;
}
