////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 17:46:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long int ll;
int main()
{
    int a,b,c;
    float t;
    int n;
    while(scanf("%d",&n) && n)
    {
        a=b=c=0;
        while(n--)
        {
            scanf("%f",&t);
            if(t<0)
                a++;
            else if(t==0)
                b++;
            else
                c++;
        }
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
