////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-25 13:08:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}

int main()
{
	int test,n,V,i,j;
	int value[1010],v[1010],f[1010];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&V);
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&value[i]);
		}
		for (i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		for (i=1;i<=n;i++)
		{
			for (j=V;j>=v[i];j--)
			{
				f[j]=max(f[j],f[j-v[i]]+value[i]);
			}
		}
		printf("%d\n",f[V]);
	}
	return 0;
}

