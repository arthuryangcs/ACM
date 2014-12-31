////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 17:23:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:380KB
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
    double x1,x2,y1,y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
        printf("%.2lf\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    }
    return 0;
}
