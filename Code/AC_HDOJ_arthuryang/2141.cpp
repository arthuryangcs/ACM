////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-03-30 17:23:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2141
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:2232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int find(__int64 a[],__int64 b,int l,int r)
{
    int min=l+(r-l)/2;
    if(a[r]<b || a[l]>b || l>r)
        return 0;
    else if(a[min]<b)
        return find(a,b,min+1,r);
    else if(a[min]>b)
        return find(a,b,l,min-1);
    else
        return 1;
}
__int64 a[505],b[505],c[505],d,e[300000];
int main()
{
    int l,m,n,s,flag;
    int i,j,k=1,q;
    while(~scanf("%d%d%d",&l,&m,&n))
    {
        for (i=0;i<l;i++)
            scanf("%I64d",&a[i]);
        for (i=0;i<m;i++)
            scanf("%I64d",&b[i]);
        for (i=0;i<n;i++)
            scanf("%I64d",&c[i]);
        for (i=0;i<l;i++)
        {
            for (j=0;j<m;j++ )
            {
                e[i*l+j]=a[i]+b[j];
            }
        }
        sort(e,e+l*n);
        sort(c,c+n);
        printf("Case %d:\n",k++);
        scanf("%d",&s);
       while(s--)
        {
            scanf("%I64d",&d);
         //   if((d-a[l-1]-c[n-1]>b[m-1])|| (d<a[0]+b[0]+c[0]))
         //       printf("NO\n");
         //   else
          //  {
                flag=0;
                for (j=0;j<n;j++)
                {
                    if(find(e,d-c[j],0,m*l-1))
                    {
                        flag=1;
                        break;
                    }
                }
                    if(flag)
                        printf("YES\n");
                    else
                        printf("NO\n");
         //   }
       }
    }
    return 0;
}
