////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 23:14:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
    int m1,m2,r1,r2,r3;
    char s[201],*p,c;
    while(scanf("%d%d%c",&m1,&m2,&c)!=EOF)
    {
        r1=r2=r3=0;
        scanf("%s",s);
        for(p=s;*p!='\0';p++)
        {
            if(*p=='A')
                r1=m1;
            else if(*p=='B')
                r2=m2;
            else if(*p=='C')
                m1=r3;
            else if(*p=='D')
                m2=r3;
            else if(*p=='E')
                r3=r1+r2;
            else if(*p=='F')
                r3=r1-r2;
        }
        printf("%d,%d\n",m1,m2);
    }
}