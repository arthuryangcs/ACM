////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-30 09:52:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1372
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int v[10][10];
int s[100][3];
int a[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int x,y,x2,y2;

int bfs(int x,int y,int n)
{
    int tx,ty;
    int c = 0;
    v[x][y]=1;
    s[0][0]=x;
    s[0][1]=y;
    s[0][2]=0;
    for (int i=0;i<=c;i++)
    {
        //cout<<s[i][0]<<" "<<s[i][1]<<" "<<s[i][2]<<endl;
        if(s[i][0]==x2 && s[i][1]==y2)
                return s[i][2];
        for (int j=0;j<8;j++)
        {
            tx=s[i][0]+a[j][0];
            ty=s[i][1]+a[j][1];
            if(tx>=0 && ty>=0 && tx<8 && ty<8 && v[tx][ty]==0)
            {
                v[tx][ty]=1;
                s[++c][0]=tx;
                s[c][1]=ty;
                s[c][2]=s[i][2]+1;
            }
        }
    }
    return 0;

}

int main()
{
    int i,j;
    char ta[5],tb[5];
    while(scanf("%s %s",ta,tb)!=EOF)
    {
        memset(v,0,sizeof(v));
        memset(s,0,sizeof(s));
        x=ta[0]-'a';
        y=ta[1]-'1';
        x2=tb[0]-'a';
        y2=tb[1]-'1';
        printf("To get from %s to %s takes %d knight moves.\n",ta,tb,bfs(x,y,0));
    }
    return 0;
}