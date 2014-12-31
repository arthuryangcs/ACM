////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-06 21:25:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <cstdio>
int main()
{
	double v,d;
	while(scanf("%lf%lf",&v,&d) != EOF)
	{
		int pass = 1,i;
		int time = 0;
		int is_finish = 0;
		while(0 == is_finish)
		{
			for(i = 1 ; i <= pass ; ++i)
			{
				v = v - d;
				++time;
				if(v <= 0)
				{
					is_finish = 1;
					break;
				}
			}
			if(is_finish)
				break;
			++pass;
			time ++;
		}
		printf("%d\n",time);
	}
	return 0;
}