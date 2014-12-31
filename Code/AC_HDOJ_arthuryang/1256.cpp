////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-20 18:01:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
char z;
void hang(int a,int b)
{
    int i;
    for (i=0;i<a;i++)
    {
        printf(" ");
    }
    for (i=0;i<b;i++)
    {
        printf("%c",z);
    }
    printf("\n");
}

void lie(int a,int b,int c)
{
    int i,j;
    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++)
        {
            printf("%c",z);
        }
        for (j=0;j<c;j++)
        {
            printf(" ");
        }
        for (j=0;j<b;j++)
        {
            printf("%c",z);
        }
        printf("\n");
    }
}

int main()
{
    int b,c,d,e,f;
    scanf("%d",&b);
    getchar();
    while(b--)
    {
        scanf("%c %d",&z,&c);
        getchar();
        d=c/6+1;
        c-=3;
        if(c%2==0)
            e=f=c/2;
        else
        {
            e=c/2;
            f=c/2+1;
        }
        hang(d,f);
        lie(e,d,f);
        hang(d,f);
        lie(f,d,f);
        hang(d,f);
        if(b)
            printf("\n");
    }
    return 0;
}
