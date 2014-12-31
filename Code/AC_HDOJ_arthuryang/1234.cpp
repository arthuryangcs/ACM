////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 13:29:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

char a[100001][3][20];
int main()
{
    int i,b,c,j,en,fi;
    scanf("%d",&b);
    for (i=0;i<b;i++)
    {
        scanf("%d",&c);
        fi=0;
        en=0;
        for(j=0;j<c;j++)
        {
            scanf("%s %s %s",a[j][0],a[j][1],a[j][2]);
            if(strcmp(a[j][1],a[fi][1])<0)
                fi=j;
            if(strcmp(a[j][2],a[en][2])>0)
                en=j;
        }
        printf("%s %s\n",a[fi][0],a[en][0]);
    }

    return 0;
}
