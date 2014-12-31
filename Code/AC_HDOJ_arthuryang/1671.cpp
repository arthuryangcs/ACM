////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-01 14:37:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:2660KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int flag=0;
struct trd
{
    int a[10];
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
    if(flag)
        return ;
    if(s[d]=='\0')
    {
        if(n)
            a[n].n++;
        int sum=0;
        for (int i=0;i<=9;i++)
        {
            sum+=a[n].a[i];
        }
        if(a[n].n>1 || sum)
            flag=1;
        return ;
    }
    if(a[n].n!=0)
    {
        flag=1;
        return ;
    }
    if(a[n].a[s[d]-'0']!=0)
    {
        insert(s,a[n].a[s[d]-'0'],d+1);
    }
    else
    {
        a[count++].init();
        a[n].a[s[d]-'0']=count-1;
        insert(s,a[n].a[s[d]-'0'],d+1);
    }
}

int search(char s[])
{
    int i=0;
    int n=0;
    while(s[i]!='\0')
    {
        if(a[n].a[s[i]-'0']==0)
            return 0;
        else
        {
            n=a[n].a[s[i]-'0'];
            i++;
        }
    }
    return a[n].n;
}
char tt[100];
int num=1;
int main()
{
    int t;
    int nn;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        a[count++].init();
        flag=0;
        scanf("%d",&nn);
        getchar();
        while(nn--)
        {
            gets(tt);
            insert(tt,0,0);
          //  cout<<flag<<endl;
        }
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
