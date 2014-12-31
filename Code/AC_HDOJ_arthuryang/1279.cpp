////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 05:45:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1279
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int f,a,b;
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&b);
        f=1;
        while(b%2==0)
            b/=2;
        if(b%2 && b!=1)
            {
                f=0;
                printf("%d",b);
                 b=3*b+1;
            }
        while(b!=1)
        {

            if(b%2)
            {
                f=0;
                printf(" %d",b);
                 b=3*b+1;
            }
            else
                b/=2;
        }
        if(f)
        {
            printf("No number can be output !");
        }
        printf("\n");
    }
    return 0;
}
