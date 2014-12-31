////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-12 15:46:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int N;
    int temp;
    int n,m,num=0;
    int i,j,kinds=0;
    scanf("%d",&N);
    temp=N-1;
    //printf("\n");
    while(N--)
    {
        if(N<temp)
        {
            printf("\n");
        }
        num=0;
        while(scanf("%d%d",&n,&m) && !(n==0 && m==0))
        {
            num++;
            kinds=0;
            for(i=1;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if((i*i+j*j+m)%(i*j)==0)
                    {
                        kinds++;
                    }
                }
            }
            printf("Case %d: %d\n",num,kinds);
        }
    }
    return 0;
}

