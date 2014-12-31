////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 16:08:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:872KB
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
int main()
{
    int n,m,tmp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        a.clear();
        n+=m;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            a.insert(tmp);
        }
        printf("%d",*a.begin());
        for (b=++a.begin();b!=a.end();b++)
        {
            printf(" %d",*b);
        }
        printf("\n");
    }
    return 0;
}
