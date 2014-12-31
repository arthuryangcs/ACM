////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-01 13:27:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:39420KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int num;
struct trd
{
    int a[26];
    int n;
    void init()
    {
        memset(a,0,sizeof(a));
        n=0;
    }
}a[3000000];
int count=0;
trd t;
void insert(char s[],int n,int d)
{
    if(s[d]=='\0')
    {
        a[n].n++;
        return ;
    }
    if(a[n].a[s[d]-'a']!=0)
    {
        insert(s,a[n].a[s[d]-'a'],d+1);
    }
    else
    {
        a[count++].init();
        a[n].a[s[d]-'a']=count-1;
        insert(s,a[n].a[s[d]-'a'],d+1);
    }
    a[n].n++;
}

int search(char s[])
{
    int i=0;
    int n=0;
    while(s[i]!='\0')
    {
        if(a[n].a[s[i]-'a']==0)
            return 0;
        else
        {
            n=a[n].a[s[i]-'a'];
            i++;
        }
    }
    return a[n].n;
}
char tt[100];
int main()
{
    a[count++].init();
    while(gets(tt),strlen(tt)>0)
    {
        insert(tt,0,0);
    }
    while(scanf("%s",tt)!=EOF)
    {
        printf("%d\n",search(tt));
    }
    return 0;
}
