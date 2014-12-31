////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 15:11:55
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h> 
int main() 
{ 
    double n;                                       
    while(scanf("%lf", &n)!= EOF) 
    { 
        printf("%.2lf\n", (float)((n>= 0)? n: (-n)));                    
    } 
    return 0; 
} 
