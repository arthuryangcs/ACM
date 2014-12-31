////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 15:11:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<string.h>

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
char a[1000001];
int b[1000001]={-1};
int main()
{

    int i,j;
    while(gets(a))
    {
        i=0;
        b[0]=-1;
        for(j=0;a[j]!='\0';j++)
        {
            if(a[j]!='5'&&b[i]!=-1)
            {
                b[i]=b[i]*10+a[j]-48;
            }
            else if(a[j]!='5'&&b[i]==-1)
            {
                b[i]=a[j]-48;
            }
            else if(a[j]=='5'&&b[i]!=-1)
            {
                i++;
                b[i]=-1;
            }
        }
        if(a[j-1]=='5')
            i--;
        qqsort(b,0,i);
        for(j=0;j<i;j++)
            printf("%d ",b[j]);
        printf("%d\n",b[i]);
    }
    return 0;
}
