////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-10-14 21:27:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2520
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,v,s,n,i;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
            scanf("%d",&n);
			s=0;v=1;
			for(i=1;i<=n;i++)
			{
				s=(s+v)%10000;
				v=(v+2)%10000;
			}
			printf("%d\n",s);
		}
	}
	return 0;
}