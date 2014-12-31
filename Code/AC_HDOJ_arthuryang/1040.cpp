////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 15:05:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
int a[1002];
int sortit(int a[],int l,int r)
{
    int pr=a[l];

    while(l<r)
    {
        while(l<r && a[r]>=pr)
            --r;
        a[l]=a[r];
        while(l<r && a[l]<=pr)
            ++l;
        a[r]=a[l];
    }
    a[l]=pr;
    return l;
}
void qqsort(int a[],int l,int r)
{
    int pr;
    if(l<r)
    {
        pr=sortit(a,l,r);
        qqsort(a,l,pr-1);
        qqsort(a,pr+1,r);
    }
}
int main()
{
    int i,n,b,j;
    scanf("%d",&b);
    for (i=0;i<b ;i++ )
    {
        a[0]=1;
        for (j=0;j<=a[0];j++)
        {
            scanf("%d",&a[j]);
        }
        qqsort(a,1,a[0]);
        for (j=1;j<=a[0];j++)
        {
            printf("%d",a[j]);
            if(j!=a[0])
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
