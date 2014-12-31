////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 14:53:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:8928KB
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

int a[1111111];
int b[1111111];
int q,w,e,r;
ll ans;
void an(int q,int w)
{
    int tmp=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=1;i<=100;i++)
    {
        for (int j=1;j<=100;j++)
        {
            tmp=q*i*i+w*j*j;
            if(tmp>=0)
                a[tmp]++;
            else
                b[-tmp]++;
        }
    }
}
void findans(int q,int w)
{
    int tmp=0;
    ans=0;
    for (int i=1;i<=100;i++)
    {
        for (int j=1;j<=100;j++)
        {
            tmp=q*i*i+w*j*j;
            if(tmp<=0)
                ans+=16*a[-tmp];
            else
                ans+=16*b[tmp];
        }

    }
}
int main()
{
    while(scanf("%d%d%d%d",&q,&w,&e,&r)!=EOF)
    {
        if(q>0 && w>0 && e>0 && r>0)
            ans=0;
        else if(q<0 && w<0 && e<0 && r<0)
            ans=0;
        else
        {
            an(q,w);
            findans(e,r);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
