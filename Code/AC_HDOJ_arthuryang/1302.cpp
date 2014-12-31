////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-03-03 14:35:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1302
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

double day (double a, double b,double c)
{
    a+=b;
    if(a>c)
        return -1;
    else
        return a;
}

double night (double a, double b)
{
    a-=b;
    if(a<0)
        return -1;
    else if(a==0)
        return -2;
    else
        return a;
}

double jian(double a,double b)
{
    if(a-b>0)
        a-=b;
    else
        a=0;
    return a;
}

int main()
{
    int i;
    float  c=0,h,u,d,f,g;
    while(scanf("%f%f%f%f",&h,&u,&d,&f),h!=0)
    {
        c=0;
        g=u/100.0*f;
        for (i=1;;i++)
        {
            c=day(c,u,h);
            if(c==-1)
            {
                printf("success on day %d\n",i );
                break;
            }
            c=night(c,d);
            if(c==-1)
            {
                printf("failure on day %d\n",i);
                break;
            }
             if(c==-2)
             {
                 printf("failure on day %d\n",1+i);
                 break;
             }
            u=jian(u,g);
        }
    }
    return 0;
}
