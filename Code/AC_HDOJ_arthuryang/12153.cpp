////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-25 17:11:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 500000
inline int ans(int a)
{

    if(a==0)
        return 0;
    int j,t,s=1,ta=a;
    for (int i=2;i<=a;i++)
    {
        j=t=1;
        while(a%i==0)
        {
            a/=i;
            j*=i;
            t+=j;
        }
        s*=t;
    }
    s-=ta;
    return s;
}
int main()
{
    int n,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        printf("%d\n",ans(a));
    }
    return 0;
}
