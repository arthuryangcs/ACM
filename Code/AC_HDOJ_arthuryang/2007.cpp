////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 17:38:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include "stdio.h"
#include "math.h"
int main()
{
	long n,m,i,sum2,sum3;
	while(scanf("%ld%ld",&n,&m)!=EOF)
	{
		if(n>m)
		{
			i=n;
			n=m;
			m=i;
		}
		sum2=sum3=0;
		for(i=n;i<=m;i++)
		{
			if(i%2==0) sum2+=pow(i,2);
			else if(i%2!=0) sum3+=pow(i,3);
		}
		printf("%ld %ld\n",sum2,sum3);
	}
}