////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-15 12:32:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3682
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:4168KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
struct aaa
{
    int x,y,z;
    bool xx,yy,zz;
    void init()
    {
        xx = yy = zz = 0;
    }
}a[1111];
int k[1111111];
int N = 1011;
void solve()
{
    scanf("%d%d ",&n,&m);
    char c,cc;
    int t,tt;
    int num = 0;
    for(int i  =0 ;i<m;i++)
    {
        a[i].init();
        scanf("%c",&c);
        scanf("=%d,",&t);
        if(c=='X')
        {
            a[i].xx = 1;
            a[i].x = t;
        }
        else if(c=='Y')
        {
            a[i].yy = 1;
            a[i].y = t;
        }
        else
        {
            a[i].zz = 1;
            a[i].z = t;
        }
        scanf("%c",&c);
        scanf("=%d ",&t);
        if(c=='X')
        {
            a[i].xx = 1;
            a[i].x = t;
        }
        else if(c=='Y')
        {
            a[i].yy = 1;
            a[i].y = t;
        }
        else
        {
            a[i].zz = 1;
            a[i].z = t;
        }
        if(a[i].xx==0)
            for(int j = 1;j<=n;j++)
                k[num++]= j*N*N + a[i].z + a[i].y*N;
        if(a[i].yy==0)
            for(int j = 1;j<=n;j++)
                k[num++]= a[i].x*N*N + a[i].z + j*N;
        if(a[i].zz==0)
            for(int j = 1;j<=n;j++)
                k[num++]= a[i].x*N*N + j + a[i].y*N;
    }
    sort(k,k+num);
    int p = 0;
    int sum = 1;
    //cout<<k[0]<<" ";
    for(int i = 1;i<num;i++)
    {
       // cout<<k[i]<<" ";
        if(k[i-1]!=k[i])
        {
            sum++;
        }
    }
    printf("%d\n",sum);
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d",&t))
    {
        while(t--) solve();
    }
    return 0;
}
