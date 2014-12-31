////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-07 17:12:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3336
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2060KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
int    h[222222];
int next[222222];
char   s[222222];
int a;
int n;
void getNext(char *p,int *next)
{
    int j,k;
    next[0]=-1;
    j=0;
    k=-1;
    while(j<n)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;
            k++;
            next[j]=k;
            if(k!=0)
                h[j]=(next[k]+1)%10007;
            else
                h[j]=0;
        }
        else
        {
            k=next[k];
        }
    }
}
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        getNext(s,next);
        a=n;
        for (int i=1; i<=n; i++)
        {
            a=(a+h[i])%10007;
        }
        printf("%d\n",a);
    }
    return 0;
}