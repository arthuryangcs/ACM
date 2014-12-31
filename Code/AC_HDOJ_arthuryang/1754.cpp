////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-30 12:40:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:1531MS
////Run memory:6456KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define MAX 200010
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
    a[1].r=m+1;
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
        if(a[i].l==m &&a[i].r==m+1)
            break;
    }
}
void add(int x,int y)
{
    int mid;
    int i=1;
    while(a[i].l!=x ||a[i].r!=x+1)
    {
        a[i].n=max(y,a[i].n);
        if((a[i].l+a[i].r)/2<=x)
        {
            i=2*i+1;
        }
        else
            i*=2;
    }
    a[i].n=max(y,a[i].n);
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

int ans(int i,int x,int y)
{
    int mid=(a[i].l+a[i].r)/2;
    if(x==a[i].l && y==a[i].r)
        return a[i].n;
    else if(x==a[i].l && y==mid)
        return a[2*i].n;
    else if(x==mid && y==a[i].r)
        return a[2*i+1].n;
    else if(mid>=y)
        return ans(2*i,x,y);
    else if(mid<=x)
        return ans(2*i+1,x,y);
    else if(x==a[i].l && y>mid)
        return max(a[2*i].n,ans(2*i+1,mid,y));
    else if(x<mid && y==a[i].r)
        return max(a[2*i+1].n,ans(2*i,x,mid));
    else
        return max(ans(2*i,x,mid),ans(2*i+1,mid,y));
}

int change(int i,int x,int y)
{
    int mid=(a[i].l+a[i].r)/2;
    if(a[i].l==x && a[i].r==x+1)
        return a[i].n=y;
    else if(mid<=x)
        return a[i].n=max(a[2*i].n,change(2*i+1,x,y));
    else
        return a[i].n=max(a[2*i+1].n,change(2*i,x,y));
}

int main()
{
    int tmp;
    int x,y;
    char tt[1000];
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        init();
        for (int i=0;i<m;i++)
        {
            scanf("%d",&tmp);
            change(1,i+1,tmp);
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s%d%d",tt,&x,&y);
            switch(tt[0])
            {
            case 'Q':
                cout<<ans(1,x,y+1)<<endl;
                break;
            case 'U':
                change(1,x,y);
                break;
            }
           // for (int j=1;j<50;j++)
           // {
           //     cout<<j<<" "<<a[j].l<<" "<<a[j].r<<" "<<a[j].n<<endl;
           // }
        }
    }
    return 0;
}
