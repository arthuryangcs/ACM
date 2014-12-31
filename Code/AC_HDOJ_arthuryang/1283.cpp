////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 23:00:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
	int m1,m2,r1,r2,r3,i;
	char c[200];
	while(scanf("%d%d",&m1,&m2)!=EOF)
	{
		r1=r2=r3=0;
		getchar();
		gets(c);
		for(i=0;c[i]!='\0';i++)
		{
			switch(c[i])
			{
			case 'A':r1=m1;break;
			case 'B':r2=m2;break;
			case 'C':m1=r3;break;
			case 'D':m2=r3;break;
			case 'E':r3=r1+r2;break;
			case 'F':r3=r1-r2;break;
			}
		}
		printf("%d,%d\n",m1,m2);
	}
	return 0;
}
 
