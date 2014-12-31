////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 12:33:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>

double a[10000][2];

double en(double a)
{
    if (a>=90 && a<=100)
        return 4;
    else if(a>=80)
        return 3;
    else if(a>=70)
        return 2;
    else if(a>=60)
        return 1;
    else
        return 0;
}

int main()
{
    double sum1,sum2;
    int b,i,flag;
    while(~scanf("%d",&b))
    {
        flag=1;
        sum1 = sum2 = 0;
        for(i=0;i<b;i++)
        {
            scanf("%lf %lf",&a[i][0],&a[i][1]);
            if(a[i][1]!=-1)
            {
                flag=0;
                sum2+=a[i][0]*en(a[i][1]);
                sum1+=a[i][0];
            }
        }
        if(flag || sum2==0)
            printf("-1\n");
        else
            printf("%.2lf\n",1.0*sum2/sum1);
    }
    return 0;
}
