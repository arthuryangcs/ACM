////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 18:12:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:392KB
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
    double m;
    int n;
    while(cin>>m>>n)
    {
        double t = m;
        for (int i=1;i<n ;i++ )
        {
            m = sqrt(m);
            t += m;
        }
        printf("%.2lf\n",t);
    }
    return 0;
}
