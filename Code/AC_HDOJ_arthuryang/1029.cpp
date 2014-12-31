////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-16 12:31:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:5296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<string.h>

int a[1000000]={0},b[1000000]={0};
int main()
{
    int n,h,i;
    while(~scanf("%d",&n))
    {
        h=n;
        memset(b,0,sizeof(b));
        while(n--)
        {
            scanf("%d",&a[n]);
        }
        for (i=0;i<h;i++)
        {
            b[a[i]]++;
            if(b[a[i]]>=(h+1)/2)
            {
                printf("%d\n",a[i]);
                break;
            }
        }
    }
    return 0;
}
