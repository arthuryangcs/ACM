////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-10 14:09:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include "stdio.h"
int main(int argc, char* argv[])
{ 
	int n,j,from,to,time; 
	while((scanf("%d",&n)==1)&&(n!=0)) 
	{  
		from = 0;  
		time = 0;  
		for(j=1;j<=n;j++)  
		{   
			scanf("%d",&to);   
			if(from<to)   
			{    
				time+=(to-from)*6+5;   
			}
			else   
			{    
				
				time+=(from-to)*4+5;   
			}
			from = to; 
		}
		printf("%d\n",time); 
	}  
	return 0;
}
