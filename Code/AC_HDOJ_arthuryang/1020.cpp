////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-19 16:22:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char a[10001];
char b[10001];
int c[10001];
int main()
{
    int i,d,s,k,la;
    scanf("%d",&d);
    getchar();
    while(d--)
    {
        k=0;
        for(i=0;i<1000;i++)
        {
            a[i]=b[i]=c[i]=0;
        }
        gets(a);
        la=strlen(a);
        for (i=0;i<la;i++)
        {
            if(c[k]==0)
            {
                b[k]=a[i];
                c[k]++;
            }
            else if(b[k]==a[i])
            {
                c[k]++;
            }
            else
            {
                i--;
                k++;
            }
        }
        for (i=0;i<=k;i++)
        {
            if(c[i]!=1)
                printf("%d",c[i]);
            printf("%c",b[i]);
        }
        printf("\n");
    }
    return 0;
}
