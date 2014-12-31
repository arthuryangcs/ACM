////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 17:42:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1286
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
int eu(int n)
{
    int ans=1;
    for (int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i;
            ans*=i-1;
            while(n%i==0)
            {
                n/=i;
                ans*=i;
            }
        }
    }
    if(n>1)
        ans*=n-1;
    return ans;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",eu(n));
    }
    return 0;
}
