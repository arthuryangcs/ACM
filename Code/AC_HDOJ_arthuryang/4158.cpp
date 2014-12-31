////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-30 16:21:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4158
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    int x,y;
};
int n,m,b,w;
int map[20][20];
int a[4][2]={0,1,0,-1,1,0,-1,0};
int nb,nw;

void bfs(int x,int y)
{
    int f1,f2;
    f1=f2=0;
    queue<node> s;
    map[x][y]=3;
    node tt;
    tt.x=x;
    tt.y=y;
    int tx,ty;
    s.push(tt);
    int ans=1;
    while(!s.empty())
    {
        tt=s.front();
        s.pop();
        x=tt.x;
        y=tt.y;
        //cout<<x<<y<<endl;
        for (int i=0;i<4;i++)
        {
            tx=x+a[i][0];
            ty=y+a[i][1];
            if(tx<=n && tx>=1 && ty<=n && ty>=1)
            {
                if(map[tx][ty]==0)
                {
                    tt.x=tx;
                    tt.y=ty;
                    s.push(tt);
                    map[tx][ty]=3;
                    ans++;
                }
                else if(map[tx][ty]==1)
                    f1=1;
                else if(map[tx][ty]==2)
                    f2=1;
            }

        }
    }
    if(f1+f2==2);
    else if(f1==1) nb+=ans;
    else if(f2==1) nw+=ans;
   // cout<<"dfasfa"<<nb<<nw<<endl;
}

int main()
{
    int ta,tb;
    while(scanf("%d",&n),n)
    {
        nb=nw=0;
        memset(map,0,sizeof(map));
        scanf("%d%d",&b,&w);
        int i,j;
        for (i=0;i<b;i++)
        {
            scanf("%d%d",&ta,&tb);
            map[ta][tb]=1;
        }
        for (i=0;i<w;i++)
        {
            scanf("%d%d",&ta,&tb);
            map[ta][tb]=2;
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if(map[i][j]==0)
                    bfs(i,j);
            }
        }
        if(nb==nw)
            cout<<"Draw"<<endl;
        else if(nb>nw)
            cout<<"Black wins by "<<nb-nw<<endl;
        else if(nb<nw)
            cout<<"White wins by "<<-nb+nw<<endl;
    }
    return 0;
}
