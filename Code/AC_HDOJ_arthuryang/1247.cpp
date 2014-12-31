////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-01 15:19:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:7736KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
struct trd
{
    int a[30];
    int n;
    void init()
    {
        memset(a,0,sizeof(a));
        n=0;
    }
}a[3000000];
int count=0;
trd t;
int ans;
void insert(char s[],int n,int d)
{
    if(s[d]=='\0')
    {
        if(n)
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
}

int sear(char s[])
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
            if(a[n].n && s[i+1]!='\0' && sear(s+i+1))
            {
                //cout<<s<<" "<<s+i+1<<endl;
                return 1;
            }
            i++;
        }
    }
    return 0;
}

char tt[50010][110];
char s[110];
int main()
{
    int nn;
    count=0;
    a[count++].init();
    ans=0;
    int i;
    for(i=0;scanf("%s",tt[i])!=EOF;i++)
    {
        insert(tt[i],0,0);
    }
    ans=i;
    for(i=0;i<ans;i++)
    {
        if(search(tt[i]))
            printf("%s\n",tt[i]);
    }
    return 0;
}
