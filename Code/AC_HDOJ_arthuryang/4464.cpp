////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 16:00:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 4464
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<string.h>
int jisuan(char a[])
{
    int i,la,sum=0;
    la=strlen(a);
    for(i=0;i<la;i++)
    {
        sum+=a[i];
    }
    return sum;
}

int main()
{
    char a[101][101];
    int i,j,k=1;
    int n,ma;
    while(~scanf("%d",&n))
    {
        getchar();
        ma=0;
        for (i=0;i<n;i++)
        {
            gets(a[i]);
            j=jisuan(a[i]);
            if(j>ma)
                ma=j;
        }
        printf("Case %d: %d\n",k,ma);
        k++;
    }
    return 0;
}
