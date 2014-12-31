////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-12-01 19:54:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4771
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:452KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
int ans;
struct len
{
    int x,y;
    int l;
};
queue<len> aa;
int pp[10][2];
int v[10];
int vv[111][111];
int np;
int ax,ay;
char ma[111][111];
int mm[111][111];
int dd[4][2]={1,0,-1,0,0,1,0,-1};
void dfs(int x,int y,int d,int t)
{
    //cout<<y<<d<<endl;;
    //if(t>ans)
    //    return;
    while(!aa.empty())
        aa.pop();
    memset(vv,0,sizeof(vv));
    v[y]=1;
    len tt,ttt;
    tt.x = pp[x][0];
    tt.y = pp[x][1];
    vv[tt.x][tt.y]=1;
    tt.l = 0;
  //  cout<<tt.x<<tt.y<<endl;
    aa.push(tt);
    while(!aa.empty())
    {
        tt = aa.front();
        if(tt.x == pp[y][0] && tt.y == pp[y][1])
        {
            t += tt.l;
            break;
        }
        aa.pop();
        for (int i=0;i<4;i++)
        {
            int xx = tt.x + dd[i][0];
            int yy = tt.y + dd[i][1];

            if(xx>0 && yy>0 && xx<=ax && yy<=ay && mm[xx][yy] && !vv[xx][yy])
            {
                ttt.x = xx;
                ttt.y = yy;
               // cout<<" "<<pp[y][0]<<pp[y][1]<<endl;
               // cout<<"s"<<xx<<yy<<endl;
                ttt.l = tt.l+1;
                vv[xx][yy]=1;
                aa.push(ttt);
            }
        }
    }
    if(aa.empty())
        {
            v[y]=0;
           // cout<<"a";
            return ;
        }
    if(d==np)
    {
        if(t<ans)
            ans=t;
        v[y]=0;
        //cout<<"b";
        return;
    }
    for (int i=1;i<=np;i++)
    {
        if(!v[i])
            dfs(y,i,d+1,t);
    }
    v[y]=0;
}
int main()
{

    while(scanf("%d%d",&ax,&ay),ax+ay)
    {
        ans=100000000;
        memset(v,0,sizeof(v));
        for (int i=0;i<ax;i++)
            scanf("%s",ma[i]);
        for (int i=0;i<ax;i++)
        {
            for (int j=0;j<ay;j++)
            {
                if(ma[i][j]=='#')
                    mm[i+1][j+1]=0;
                else if(ma[i][j]=='.')
                    mm[i+1][j+1]=1;
                else
                {
                    mm[i+1][j+1]=1;
                    pp[0][0] = i+1;
                    pp[0][1] = j+1;
                }
            }
        }
        scanf("%d",&np);
        for (int i=1;i<=np;i++)
            scanf("%d%d",&pp[i][0],&pp[i][1]);
        for (int i=1;i<=np;i++)
            dfs(0,i,1,0);
        printf("%d\n",ans==100000000? -1:ans);
    }
    return 0;
}