////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 15:25:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:608KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int d;
int a[1001][1001]={0},b[2][1001]={0};
int main()
{
    int i,j,n=2,sd,sum;
    scanf("%d",&sd);
    while(sd--)
    {
        n=2;
        scanf("%d",&d);
        for (i=1;i<=d ;i++ )
        {
            for (j=1;j<=i ;j++ )
            {
                scanf("%d",&a[i][j]);
            }
        }
        b[1][1]=a[1][1];
        for (;n<=d;n++)
        {
            b[2][1]=b[1][1]+a[n][1];
            b[2][n]=b[1][n-1]+a[n][n];
            for (i=2;i<n ;i++ )
            {
                b[2][i]=a[n][i]+(b[1][i]<b[1][i-1]?b[1][i-1]:b[1][i]);
            }
            for (i=1;i<=n ;i++ )
                b[1][i]=b[2][i];
          }
        sum=b[1][1];
        for(i=2;i<=d;i++)
        {
            if(sum<b[1][i])
                sum=b[1][i];
        }
        printf("%d\n",sum);
    }
}
