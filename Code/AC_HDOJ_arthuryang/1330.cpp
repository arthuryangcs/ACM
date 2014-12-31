////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-03-30 11:19:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1330
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,flag=0;
    double sum;
    printf("# Cards  Overhang\n");
    while(scanf("%d",&n)!=EOF)
    {
	
	sum=0.0;
	for(i=1;i<=n;i++)
		sum=sum+1.0/(2*i);
        printf("%5d     %0.3lf\n",n,sum);
    }
    return 0;
}