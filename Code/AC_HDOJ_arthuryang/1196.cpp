////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 11:30:50
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main()
{
    int a,b;
    while(scanf("%d",&a),a!=0)
    {
        b=1;
        for (b=1;a%b==0;b*=2);
        printf("%d\n",b/2);
    }
    return 0;
}
