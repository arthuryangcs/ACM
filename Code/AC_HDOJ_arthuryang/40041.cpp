////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-04-14 16:57:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4004
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:572KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int l,n,m;
long long int al,ar;
long long int a[1000000];

int pass(long long int mid)
{
    int i=1,j=0,step=0;
    while(i<=n+1)
    {
        if(a[i]-a[j]>mid)
            return 0;
        step++;
        while(a[i]-a[j]<=mid&&i<=n+1)
            i++;
        j=i-1;

    }
    if(step>m)
        return 0;
    else
        return 1;
}
int main()
{
    while(~scanf("%lld %lld %lld",&l,&n,&m))
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        a[n+1] = l;
        a[0] = 0;
        sort(a,a+n+1);
        al=0;
        ar=l;
        long long mid=(al+ar)/2;
        while(al<ar)
        {
            mid=(al+ar)/2;
            if (pass(mid))
            {
                ar=mid-1;
            }
            else
            {
                al=mid+1;
            }
        }
        while(pass(mid))
            mid--;
        while(!pass(mid))
            mid++;
        printf("%d\n",mid);
    }
    return 0;
}
