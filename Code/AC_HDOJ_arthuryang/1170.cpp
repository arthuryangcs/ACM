////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 16:36:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,i;
    char j;
    scanf("%d",&i);
    while(i--)
    {
        getchar();
        scanf("%c %d %d",&j,&a,&b);
        switch(j)
        {
        case '+':
            printf("%d\n",a+b);
            break;
        case '-':
            printf("%d\n",a-b);
            break;
        case '*':
            printf("%d\n",a*b);
            break;
        case '/':
            if (a%b!=0)
                printf("%.2f\n",a*1.0/b);
            else
                printf("%d\n",a/b);
            break;
        }
    }
    return 0;
}
