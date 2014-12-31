////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 14:48:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1098
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int gcd(int a,int b)
{
    return b==0? a:gcd(b , a%b);
}

int pd(int a,int b)
{
    int t;
    if (a<b)
        t=a,a=b,b=t;
    if (18%gcd(a,b)==0)
        return 1;
    else
        return 0;
}

int main()
{
    int a,b;
    while(~scanf("%d",&a))
    {
        if(pd(65,a))
        {
            for(b=1;;b++)
            {
                if((b*65-18)%a == 0)
                    {
                        printf("%d\n", (b*65-18)/a);
                        break;
                    }
            }
        }
        else
            printf("no\n");
    }
    return 0;
}
