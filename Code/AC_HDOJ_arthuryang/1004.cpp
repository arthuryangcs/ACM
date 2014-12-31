////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2012-12-28 11:34:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<string.h>
int main()
{
	int num,i,max=0,j,cmp[1000];
	char color[1000][16];
	do
	{
		scanf("%d",&num);
		if(num==0) break;
		for(i=0;i<num;i++)
		{
			scanf("%s",&color[i]);
			cmp[i]=1;
			for(j=0;j<i;j++)
			{
				if(strcmp(color[i],color[j])==0) 
					cmp[j]++;
				if(cmp[j]>cmp[max])
					max=j;
			}
		}
		printf("%s\n",color[max]);
	}while (1);
	return 0;
}
