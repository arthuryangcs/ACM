////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-06 20:10:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1262
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <cstdio>

int main()
{
	int a[10005];
	int n;
	int i;
	for (i=2;i<=10005;i++)
		a[i]=1;
	for (i=2;i<=100;i++)
	{
		for (;a[i]==0;i++);
		for (int j=i*i;j<=1e4;j+=i)
		{
			a[j] = 0;
		}
	}

	while(~scanf("%d",&n))
	{
		for(i=n/2;a[i]+a[n-i]!=2;i--);
		printf("%d %d\n",i,n-i);
	}
	return 0;
}