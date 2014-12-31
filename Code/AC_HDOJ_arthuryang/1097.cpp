////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 20:10:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,j,c[10];
    while(~scanf("%d %d",&a,&b))
    {
        a%=10;
        c[1]=a;
       for(j=2;j<10;j++)
       {
           c[j]=(a*c[j-1])%10;
           if(c[j]==a)
            break;
       }
       b%=(j-1);
       if(b)
            printf("%d\n",c[b]);
        else
            printf("%d\n",c[j-1]);
    }
    return 0;
}
