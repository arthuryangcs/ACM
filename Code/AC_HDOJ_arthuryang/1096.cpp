////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-14 20:54:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b,sum,i,as[1001];
    scanf("%d",&a);
    while(a--)
    {
		sum=0;
        scanf("%d",&b);
        for(i=0;i<b;i++)
        {
            scanf("%d",&as[i]);
            sum+=as[i];
        }
		printf("%d\n",sum);
		if(a!=0)
			printf("\n");
    }
    return 0;
}