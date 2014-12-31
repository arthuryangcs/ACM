////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-12 14:25:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1013
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int jisuan(long  a)
{
	long i,n;
	i=a;
	n=0;
	while(i)
	{
		n=n+i%10,i/=10;
		if(!i && n>=10)
			i=n,n=0;
	}
	return n;
}

int main()
{
    char n[100000];
    long i,a;
    while(1)
    {
        scanf("%s",n);
        if(n[0]=='0' && n[1]=='\0')
            break;
        for (a=i=0;i<100000 ;i++ )
        {
            if(n[i]=='\0')
            {
                if(a>=10)
                {
                    a=jisuan(a);
                    break;
                }
                else
                    break;
            }
            a+=(int)(n[i]-'0');
        }
        printf("%d\n",a);
    }
    return 0;
}
