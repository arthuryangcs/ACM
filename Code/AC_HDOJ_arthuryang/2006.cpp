////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 17:36:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,sum,num;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;
		while(n--)
		{
			scanf("%d",&num);
			if(num%2==1)
				sum*=num;
		}
		printf("%d\n",sum);
	}
	return 0;
}