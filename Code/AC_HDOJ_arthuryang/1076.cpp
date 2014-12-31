////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 19:57:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int leap(int year)
{
    if(year%4==0 && year%100!=0 || year %400==0)
        return 1;
    else
        return 0;
}

int main()
{
    int a,b,c,i,j,f;
    scanf("%d",&a);
    for (i=0;i<a;i++)
    {
        f=0;
        scanf("%d%d",&b,&c);
        while(f!=c)
        {

            if(leap(b)==1)
                f++;
                b++;
        }
        b--;
        printf("%d\n",b);
    }
    return 0;
}
