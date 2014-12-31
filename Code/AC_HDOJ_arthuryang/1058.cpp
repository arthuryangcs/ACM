////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 10:50:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int h[6000]={0};
int mi(a,b,c,d)
{
    if(a>b)
        a=b;
    if(a>c)
        a=c;
    if(a>d)
        a=d;
    return a;
}
int main()
{
    int n;
    int i,a1,a2,a3,a4,b,c,d,e;
    a1=a2=a3=a4=1;
    h[1]=1;
    for (i=2;i<6000;i++)
    {
        b=h[a1]*2;
        c=h[a2]*3;
        d=h[a3]*5;
        e=h[a4]*7;
        h[i]=mi(b,c,d,e);
        if(h[i]==b)
            a1++;
        if(h[i]==c)
            a2++;
        if(h[i]==d)
            a3++;
        if(h[i]==e)
            a4++;
    }
    while(scanf("%d",&n),n!=0)
    {

        if(n%10==1&&n!=11&&n%100!=11)
            printf("The %dst humble number is %d.\n",n,h[n]);
        else if(n%10==2&&n!=12&&n%100!=12)
            printf("The %dnd humble number is %d.\n",n,h[n]);
        else if(n%10==3&&n!=13&&n%100!=13)
            printf("The %drd humble number is %d.\n",n,h[n]);
        else
            printf("The %dth humble number is %d.\n",n,h[n]);
    }
    return 0;
}
