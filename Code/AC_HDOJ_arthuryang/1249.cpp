////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 16:34:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1249
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
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
using namespace std;
typedef long long ll;
set<int> a;
set<int>::iterator b;
int n,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",3*n*n-3*n+2);
    }
    return 0;
}
