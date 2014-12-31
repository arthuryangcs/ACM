////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-07 17:13:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4252
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:320KB
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
#include <vector>
#include <stack>
using namespace std;
int n,t;
stack<int> a;
int main()
{
    int num;
    int nn=1;
    while(scanf("%d",&n)!=EOF)
    {
        num=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t==0)
            {
                while(!a.empty())
                {
                    a.pop();
                    num++;
                }
                continue;
            }
            while(!a.empty() && t<a.top())
            {
                a.pop();
                num++;
            }
            if(a.empty() || t>a.top())
            {
                a.push(t);
                continue;
            }
            if(t==a.top())
                continue;
        }
        while(!a.empty())
        {
            a.pop();
            num++;
        }
        printf("Case %d: %d\n",nn++,num);
    }
    return 0;
}

