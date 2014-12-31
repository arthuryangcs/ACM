////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-15 12:33:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:640KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int a[100008];
main()
{
	long maxSum = 0, thisSum = 0,left=1,right,j,l;
	int i,b,c;
	scanf("%d",&b);
	for(i=1;i<=b;i++)
	{
		maxSum = -10007, thisSum = 0,left=1,right=0,l=1;
		scanf("%d",&c);
		for (j = 1; j <=c; j++)  
		{ 
			scanf("%d",&a[j]);
			thisSum += a[j];  
			if (thisSum > maxSum) 
			{
				right=j;
				left=l;
				maxSum = thisSum; 
			}
			if (thisSum < 0 )  
			{
				l=j+1;
				thisSum = 0;  
			}

		}
		
		printf("Case %d:\n",i);
		printf("%d %d %d\n",maxSum,left,right);
		if(i!=b)
			printf("\n");
	}
}
