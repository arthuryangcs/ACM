////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 11:24:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,i,flag=1;
    while(~scanf("%d",&a))
    {
        flag=1;
        if(a==1){
             printf("%d",1);
             continue;
        }

        for (i=2;i<=a;i++)
        {
            if(a%i==0 &&flag)
            {
                flag=0;
                printf("%d",i);
                a/=i;
                i--;
            }
            else if(a%i==0)
            {
                a/=i;
                printf("*%d",i);
                i--;
            }

        }
        printf("\n");
    }
    return 0;
}
