////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 15:44:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int e(int a[],int l,int r)
{
    int ll,lr,la;
    la=a[l];
    ll=l;
    lr=r;
    while(ll<lr)
    {
        if(ll<lr && a[lr]>=la)
            lr--;
        a[ll]=a[lr];
        if(ll<lr &&a[ll]<=la)
            ll++;
        a[lr]=a[ll];
    }
    a[ll]=la;
    return ll;
}

void qqsort(int a[],int l,int r)
{
    int b;
    if(l<r)
    {
        b=e(a,l,r);
        qqsort(a,l,b-1);
        qqsort(a,b+1,r);
    }
}

int main()
{
    int a[10001],b,i;
   while( ~ scanf("%d",&b))
   {
       
    for (i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
    qqsort(a,0,b-1);
    printf("%d\n",a[b/2]);
   }
    return 0;
}
