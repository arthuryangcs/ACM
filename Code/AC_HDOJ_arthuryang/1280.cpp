////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 14:16:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1280
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:28088KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<int,vector<int>,less<int> > a;
int n,m;
int b[4000];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                a.push(b[i]+b[j]);
            }
        }

        cout<<a.top();
        a.pop();
        m--;
        while(m-- && !a.empty())
        {
            cout<<" "<<a.top();
            a.pop();
        }
        cout<<endl;
    }
    return 0;
}
