////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-04-30 10:36:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:208KB
//////////////////System Comment End//////////////////
//#include<iostream>
//#include<cmath>
//using namespace std;
#include<stdio.h>
#include<math.h>
int main()
{
	__int32 n,m,jishu;
	int prime(int x);
	while(scanf("%I32d",&n)!=EOF)
	{
		jishu=0;
		while(n--)
		{
			scanf("%I32d",&m);
			if(prime(m))
			jishu+=1;
		}
		//cout<<jishu<<endl;
		printf("%I32d\n",jishu);
	}
	return 0;
}
int prime(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}