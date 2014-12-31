////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-06-20 20:40:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4438
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<stdio.h>  
int main()  
{  
    int T;  
    double x,y,p,q,ans1,ans2;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%lf%lf%lf%lf",&x,&y,&p,&q);  
        ans1=x*(1-q)+q*(p*x+p*y);  
        ans2=y*q+(1-q)*(p*x+p*y);  
        if(ans1>ans2)  
        printf("tiger %.4lf\n",ans1);  
        else  
        printf("wolf %.4lf\n",ans2);  
    }  
    return 0;  
}  