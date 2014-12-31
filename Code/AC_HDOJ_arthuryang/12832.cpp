////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 23:18:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main()
{
    char str[300],c;
    long r1,r2,r3,m1,m2,i;
    while(scanf("%ld%ld%c",&m1,&m2,&c)!=EOF)
    {
        r1=r2=r3=0;
        scanf("%s",str);
        for (i=0;str[i]!='\0';i++)
        {
            if(str[i]=='A')
                r1=m1;
            else if(str[i]=='B')
                r2=m2;
            else if(str[i]=='C')
                m1=r3;
            else if(str[i]=='D')
                m2=r3;
            else if(str[i]=='E')
                r3=r1+r2;
            else if(str[i]=='F')
                r3=r1-r2;
        }
        printf("%ld,%ld\n",m1,m2);
    }
    return 0;
}
