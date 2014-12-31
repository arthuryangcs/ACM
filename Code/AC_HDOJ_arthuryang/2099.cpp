////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-14 16:57:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2099
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
    while(~scanf("%d%d",&a,&b),a+b)
    {
        a = 100*a;
        int i;
        int f=1;
        for (i = a;i<=a+99;i++)
        {
            if(i%b == 0)
            {
                if(f)
                {
                    f=0;
                    printf("%02d",i-a);
                }
                else
                    printf(" %02d",i-a);
            }
        }
        printf("\n");
    }
    return 0;
}
