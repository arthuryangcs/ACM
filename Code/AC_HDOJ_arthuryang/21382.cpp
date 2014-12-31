////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-04-30 11:05:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
bool witness(__int64 a,__int64 n)
{
    __int64 t,d,x;
    d=1;
    int i=ceil(log(n-1.0)/log(2.0)) - 1;
    for(;i>=0;i--)
    {
        x=d;  d=(d*d)%n;
        if(d==1 && x!=1 && x!=n-1) return true;
        if( ((n-1) & (1<<i)) > 0)
            d=(d*a)%n;
    }
    return d==1? false : true;
}
bool miller_rabin(__int64 n)
{
    int s[]={2,7,61};
    if(n==2)    return true;
    if(n==1 || ((n&1)==0))    return false;
    for(int i=0;i<3;i++)
        if(witness(s[i], n))    return false;
    return true;
}
int main()
{
    int n,cnt;
    __int64 a;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        while(n--)
        {
            scanf("%I64d",&a);
            if(miller_rabin(a))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}