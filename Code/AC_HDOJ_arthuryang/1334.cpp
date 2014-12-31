////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-03-30 12:38:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1334
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int i,j,k,l;
	int a[201];
	for(i=1;i<=200;i++)
		a[i]=i*i*i;
	for(i=1;i<201;i++)
	{
		for(j=2;j<201;j++)
		{
			for(k=j;k<=200;k++)
			{
				for(l=k;l<201;l++)
				{
					if(a[i]==a[j]+a[k]+a[l])
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
				}
			}
		}
	}
	return 0;
}
