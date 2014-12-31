////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-07 17:11:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4255
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:956KB
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
int ma[201][201];
int m[201][201];
int b[4][2]={1,0,0,1,-1,0,0,-1};
void init()
{
    int step=1;
    int f=0;
    int flag=0;
    int x=100,y=100;
    ma[x][y]=1;
    while( ma[x][y]<40000)
    {
        for (int i=0;i<step && ma[x][y]<40000;i++)
        {
            ma[x+b[f][0]][y+b[f][1]]=ma[x][y]+1;
            x+=b[f][0];
            y+=b[f][1];
        }
        if(f<3)
            f++;
        else
            f=0;
        if(flag==1)
        {
            flag=0;
            step++;
        }
        else
        {
            flag=1;
        }
    }
}
int p[40001];
int prim()
{
    int flag;
    p[1]=0;
    for (int i=2;i<=40000;i++)
    {
        flag=1;
        for (int j=2;j<i;j++)
            if(i%j==0)
            {
                flag=0;
                break;
            }
        p[i]=flag;
    }
}
struct dian
{
    int x,y;
    int n;
}tmp;
int s,e;
int x,y;
int h;
int v[201][201];
queue<dian> ss;
void bfs()
{
    int tx,ty;
    int i,j;
    while(!ss.empty())
        ss.pop();
    memset(v,0,sizeof(v));
    for (i=1;i<=200;i++)
    {
        for (j=1;j<=200;j++)
            if(ma[i][j]==s)
                break;
        if(ma[i][j]==s)
                break;
    }
    tmp.x=i;
    tmp.y=j;
    tmp.n=0;
    ss.push(tmp);
    v[i][j]=1;
    for (i=1;i<=200;i++)
    {
        for (j=1;j<=200;j++)
            if(ma[i][j]==e)
                break;
        if(ma[i][j]==e)
                break;
    }
    while(!ss.empty())
    {
        tmp=ss.front();
        ss.pop();
        x=tmp.x;
        y=tmp.y;
        h=tmp.n;
        if(x==i && y==j)
        {
            printf("%d\n",h);
            return ;
        }
        for (int k=0;k<4;k++)
        {
            tx=x+b[k][0];
            ty=y+b[k][1];
            if(tx<=200 && ty<=200 && tx>=1 && ty>=1 && m[tx][ty]==0 && v[tx][ty]==0)
            {
                tmp.x=tx;
                tmp.y=ty;
                v[tx][ty]=1;
                tmp.n=h+1;
                ss.push(tmp);
            }
        }
    }
    printf("impossible\n");
}
int main()
{
    init();
    prim();
    for (int i=1;i<=200;i++)
        for (int j=1;j<=200;j++)
            m[i][j]=p[ma[i][j]];
    int num=1;
    while(scanf("%d%d",&s,&e)!=EOF)
    {
        printf("Case %d: ",num++);
        bfs();
    }
}