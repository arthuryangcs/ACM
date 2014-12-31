////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-30 11:24:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:1828KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define MAX 50010
using namespace std;
struct xds
{
    int l;
    int r;
    int n;
}a[4*MAX];
int n,m,t;
void init()
{
    a[1].l=1;
    a[1].r=n+1;
    a[1].n=0;
    for (int i=2;;i++)
    {
        if(i%2==0)
        {
            a[i].l=a[i/2].l;
            a[i].r=(a[i/2].r+a[i/2].l)/2;
            a[i].n=0;
        }
        else
        {
            a[i].r=a[i/2].r;
            a[i].l=(a[i/2].r+a[i/2].l)/2;
            a[i].n=0;
        }
        if(a[i].l==n &&a[i].r==n+1)
            break;
    }
}
void add(int x,int y)
{
    int mid;
    int i=1;
    while(a[i].l!=x ||a[i].r!=x+1)
    {
        a[i].n+=y;
        if((a[i].l+a[i].r)/2<=x)
        {
            i=2*i+1;
        }
        else
            i*=2;
    }
    a[i].n+=y;
}
int sub(int i,int x,int y)
{
    int mid=(a[i].l+a[i].r)/2;
    if(x==a[i].l && y==mid)
        return a[2*i].n;
    else if(x==mid && y==a[i].r)
        return a[2*i+1].n;
    else if(mid>=y)
        return sub(2*i,x,y);
    else if(mid<=x)
        return sub(2*i+1,x,y);
    else if(x==a[i].l && y>mid)
        return a[2*i].n+sub(2*i+1,mid,y);
    else if(x<mid && y==a[i].r)
        return a[2*i+1].n+sub(2*i,x,mid);
    else
        return sub(2*i,x,mid)+sub(2*i+1,mid,y);
}
int main()
{
    int tmp;
    int x,y;
    char tt[1000];
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        scanf("%d",&n);
        init();
        for (int j=0;j<n;j++)
        {
            scanf("%d",&tmp);
            add(j+1,tmp);
        }
        while(scanf("%s",tt),tt[0]!='E')
        {
            scanf("%d%d",&x,&y);
            if(tt[0]=='A')
                add(x,y);
            else if(tt[0]=='S')
                add(x,-y);
            else
                cout<<sub(1,x,y+1)<<endl;
        }
    }
    return 0;
}
