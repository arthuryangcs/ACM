////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-19 16:54:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char a[1001],b[1001],e[1001],g[1001];
int main()
{
    int c,i,d,top,k,flag,gk;
    while(~scanf("%d",&k))
    {
        scanf("%s %s",a,b);
        memset(e,0,sizeof(e));
        c=d=top=gk=0;
        flag=1;
        while(d<k)
        {
            if(a[c]==b[d])
            {
                c++;
                d++;
                g[gk++]=1;
                g[gk++]=2;
            }
            else if( top && e[top]==b[d])
            {
                g[gk++]=2;
                top--;
                d++;
            }
            else if(c<k)
            {
                e[++top]=a[c++];
                g[gk++]=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("Yes.\n");
            for (i=0;i<gk;i++)
            {
                if(g[i]==1)
                    printf("in\n");
                else
                    printf("out\n");
            }
            printf("FINISH\n");
        }

        else
        {
            printf("No.\n");
            printf("FINISH\n");
        }

    }
    return 0;
}
