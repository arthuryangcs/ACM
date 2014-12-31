////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 19:12:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b;
    int i;
    while(1)
    {
        scanf("%lf",&a);
        if(a==0.00)
            break;
        b=0;
        i=2;
        while(b<a)
        {
            b+=1.0/i;
            i++;
        }
        printf("%d card(s)\n",i-2);
    }
    return 0;
}
