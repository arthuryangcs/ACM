////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 05:13:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int min(int a,int b,int c)
{
    int mi;
    mi=a;
    if(b<mi)
        mi=b;
    if(c<mi)
        mi=c;
    return mi;
}

int main()
{
    int s[1000]={0};
    int a=0,b=0,c=0,i=0,n,m,j;
    while(s[i]<=10000)
    {
        i++;
        s[i]=min(s[a]+150,s[b]+200,s[c]+350);
        if(s[i]==s[a]+150)
            a++;
        if(s[i]==s[b]+200)
            b++;
        if(s[i]==s[c]+350)
            c++;
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(j=0;j<i;j++)
        {
            if(s[j]==m)
            {
                printf("0\n");
                break;
            }
            else if(s[j]<m && s[j+1]>m)
            {
                printf("%d\n",m-s[j] );
            }

        }
    }
    return 0;
}
