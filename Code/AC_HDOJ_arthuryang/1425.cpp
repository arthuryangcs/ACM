////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 14:22:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:3928KB
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
int b;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        while(!a.empty())
            a.pop();
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b);
            a.push(b);
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
