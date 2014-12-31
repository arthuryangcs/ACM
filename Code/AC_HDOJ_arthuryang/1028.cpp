////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-16 11:35:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int a[130][130]={0};
int main()
{
    int n,i,j;
    for (i=1;i<=120;i++)
    {
        a[i][1]=a[1][i]=1;
    }
    for (i=1;i<121;i++)
    {
        for (j=1;j<121;j++)
        {
            if(i>j)
                a[i][j]=a[i-j][j]+a[i][j-1];
            else if(i==j)
                a[i][j]=1+a[i][j-1];
            else
                a[i][j]=a[i][i];
        }
    }
    while(~scanf("%d",&n))
    {
         printf("%d\n",a[n][n]);
    }
    return 0;
}
