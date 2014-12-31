////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 22:31:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int as[1001];

int change(int a)
{
    int b=0;
    while(a)
    {
        b=10*b+a%10;
        a/=10;
    }
    return b;
}

int equ(int a,int b)
{
    if (a!=b)
        return 1;
    else
        return 0;
}

int main()
{
    int a,i,j;
    i=1;
    while(~scanf("%d",&a))
    {
        i=1;
        as[1]=a;
        while(equ(as[i],change(as[i])))
        {
            i++;
            as[i]=as[i-1]+change(as[i-1]);
        }
        printf("%d\n",i-1);
        for(j=1;j<i;j++)
            printf("%d--->",as[j]);
        printf("%d\n",as[j]);
    }

    return 0;
}
