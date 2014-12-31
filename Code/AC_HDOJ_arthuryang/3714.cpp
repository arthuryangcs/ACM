////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-23 11:02:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3714
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:444KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];

double ans;
int t,n;
double mid1,mid2,l,r;
double anss(double ta)
{
    double ma=-1e10;
    double tmp;
    for (int i=0;i<n;i++)
    {
        tmp=a[i]*ta*ta+b[i]*ta+c[i];
        if(tmp>ma)
            ma=tmp;
    }
    return ma;
}

int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        l=0;
        r=1000;
        for (int i=0;i<100;i++)
        {
            mid1=(l*2+r)/3;
            mid2=(l+r*2)/3;
            if(anss(mid1)<anss(mid2))
            {
                r=mid2;
            }
            else
            {
                l=mid1;
            }
        }
        printf("%.4lf\n",anss((l+r)/2));
    }
    return 0;
}
