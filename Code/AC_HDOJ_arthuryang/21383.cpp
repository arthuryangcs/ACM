////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-04-30 11:34:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
bool witness(__int64 a,__int64 n)
{
    __int64 t,u,x0,x1,b,i;
    u=n-1;
    t=0;
    while(u%2==0)
    {
        u/=2;
        t++;
    }
    b=a;
    x0=1;
    while(u)
    {
        if(u%2)
        x0=x0*b%n;
        u/=2;
        b=b*b%n;
    }
    for(i=0;i<t;i++)
    {
        x1=x0*x0%n;
        if(x1==1 && x0!=1 && x0!=n-1)    return true;
        x0=x1;
    }
    if(x0!=1)    return true;
    return false;
}
bool miller_rabin(__int64 n)
{
    __int64 s[]={2,7,61};
    int i;
    if(n==2)    return true;
    if(n==1 || ((n&1)==0))    return false;
    for(i=0;i<3;i++)
        if(witness(s[i], n))    return false;
    return true;
}
main()
{
    int n,cnt;
    __int64 a;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        while(n-->0)
        {
            scanf("%I64d",&a);
            if(miller_rabin(a)) cnt++;
        }
        printf("%d\n",cnt);
    }
    system("pause");
}