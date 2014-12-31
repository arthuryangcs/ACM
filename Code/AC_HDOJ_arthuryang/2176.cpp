////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-25 11:34:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2176
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1092KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define HJ 1.6180339887498948482
int a[1000100];
int main()
{
    int  n,b,t;
    int ans;
    while(scanf("%d",&n),n)
    {
        ans=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            ans^=a[i];
        }
        if(ans!=0)
        {
            printf("Yes\n");
            for (int i=0;i<n;i++)
            {
                b=a[i]^ans;
                if(b<a[i])
                {
                    printf("%d %d\n",a[i],b);
                }
            }
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
