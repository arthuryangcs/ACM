////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-06-22 13:49:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

#define MAX 10
char maze[MAX][MAX];
int N,M,T;
int dx,dy;//迷宫出口 
bool escape;//是否有解 

void dfs(int sx,int sy,int t)
{
    if(sx<=0 || sx>N || sy<=0 || sy>M)//防止越界 
 return;
    if(escape==true || (sx==dx && sy==dy && t==0))//符合条件 
 {
        escape=true;
        return;
    }
    
    int temp=t-abs(sx-dx)-abs(sy-dy);
    if(temp<0 || temp&1)//奇偶性剪枝 
 return;
    
    maze[sx][sy]='X';//走过的路径做标记 
    //深搜 
 if(maze[sx+1][sy] != 'X'){
        dfs(sx+1,sy,t-1);
        if(escape) return;}
    if(maze[sx][sy+1] != 'X'){
        dfs(sx,sy+1,t-1);
        if(escape) return;}
    if(maze[sx-1][sy] != 'X'){
        dfs(sx-1,sy,t-1);
        if(escape) return;}
    if(maze[sx][sy-1] != 'X'){
        dfs(sx,sy-1,t-1);
        if(escape) return;}
    maze[sx][sy]='.';//回溯，所以取消标记 
}

int main()
{
    int sx,sy;//迷宫入口 
 while(cin >> N >> M >> T)
    {
        if(N==0 && M==0 && T==0)
            break;
        
        int wall=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cin >> maze[i][j];
                if(maze[i][j]=='X')
                    wall++;
                if(maze[i][j]=='S'){//找出迷宫入口 
 sx=i;sy=j;}
                else if(maze[i][j]=='D'){
                    dx=i;dy=j;}
            }
        }
        
        if(N*M-wall<=T){//剪枝条件之一：可走方格数比规定时间还少 
 cout << "NO\n";
            continue;}
        
        escape=false;
        dfs(sx,sy,T);//重点 
 if(escape)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}