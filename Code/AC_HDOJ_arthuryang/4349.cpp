////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-12-01 20:00:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4349
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        int n=0;
        while(t)
        {
            if(t%2==1)
                n++;
            t/=2;
        }
        printf("%d\n",int(pow(2,n)));
    }
    return 0;
}