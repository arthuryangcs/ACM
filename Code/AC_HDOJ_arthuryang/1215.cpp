////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-25 16:56:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 500000
int f[MAX+1];
int main()
{
    int n,a;
    f[0]=f[1]=0;
    for(int i=1;i<=MAX/2;i++)
        for(int j=i+i;j<=MAX;j+=i)
            f[j]+=i;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a);
        printf("%d\n",f[a]);
    }
    return 0;
}
