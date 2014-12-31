////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-10 14:19:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
	int i=2,n;
	double j=2.5;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for(n=3;n<10;n++)
	{
		i*=n;
		j+=1/(i*1.0);
		printf("%d %.9lf\n",n,j);
	}
	return 0;
}