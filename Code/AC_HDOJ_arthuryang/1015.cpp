////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-02 15:58:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
double ans;
int visited[100];
char ma[100];
double an[100];
int flag;
void display()
{
    for (int i=0;i<5 ;i++ )
    {
        printf("%c",char(an[i]+'A'-1));
    }
    printf("\n");
}

void a(int m)
{
    if(flag==1)
    {
        return ;
    }
    if(5==m)
    {
        if(an[0]-
           an[1]*an[1]+
           an[2]*an[2]*an[2]-
           an[3]*an[3]*an[3]*an[3]+
           an[4]*an[4]*an[4]*an[4]*an[4]==ans)
           {
               flag=1;
               display();
           }
    }
    else
    {
        for (int i=n-1;i>=0; i-- )
        {
            if(visited[i]==0 )
            {
                visited[i]=1;
                an[m]=ma[i]-'A'+1;
                a(m+1);
                visited[i]=0;
            }
        }
    }
}
int main()
{
    while(scanf("%lf %s",&ans,ma),ans || strcmp(ma,"END"))
    {
        flag=0;
        memset(visited,0,sizeof(visited));
        n = strlen(ma);
        sort(ma,ma+n);
        a(0);
        if(flag==0)
            printf("no solution\n");
    }
    return 0;
}
