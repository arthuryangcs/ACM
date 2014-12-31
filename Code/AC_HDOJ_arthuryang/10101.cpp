////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-06-22 14:26:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:328KB
//////////////////System Comment End//////////////////
#include<stdio.h>
 #include<iostream>
 #include<math.h>
 using namespace std;
 
 bool escape;
 int direction[4][2]={ { 0,-1 } , { 0,1 } , { 1,0 } , { -1,0 } };//移动的四个方向
 int n,m,t,sx,sy,dx,dy;
 char map[10][10];
 
 void dfs(int nx,int ny,int nt)
 {
     int i;
     if(abs(nx-dx)+abs(ny-dy)>t-nt)
         return ;
     if(nx==dx&&ny==dy&&nt==t)
     {
         escape=1;
         return ;
     }
     if(escape)
         return ;//因为少了这句，所以Time Limit Exceed 15次。。
     for(i=0;i<4;i++)
     {
         if(nx+direction[i][0]>=0&&nx+direction[i][0]<n&&ny+direction[i][1]>=0&&ny+direction[i][1]<m)
             if(map[nx+direction[i][0]][ny+direction[i][1]]!='X')
             {
                 map[nx+direction[i][0]][ny+direction[i][1]]='X';
                 dfs(nx+direction[i][0],ny+direction[i][1],nt+1);
                 map[nx+direction[i][0]][ny+direction[i][1]]='.';
             }
     }
     return ;
 }
 
 
 
 int main()
 {
     int count=0,wall;
     //freopen("input.txt","r",stdin);
     int i,j;
     while(cin>>n>>m>>t&&(n||m||t))
     {
         wall=0;
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 cin>>map[i][j];
                 if(map[i][j]=='S')
                 {
                     sx=i;
                     sy=j;
                 }
                 else if(map[i][j]=='D')
                 {
                     dx=i;
                     dy=j;
                 }
                 else if(map[i][j]=='X')
                     wall++;
             }
         }
         if(n*m-wall<=t||((sx+dx+sy+dy)&1)!=(t&1))//后半句是奇偶剪枝，很关键
         {
             printf("NO\n");
             continue;
         }
         escape=0;
         map[sx][sy]='X';
         dfs(sx,sy,0);
         if(escape)
             printf("YES\n");
         else 
             printf("NO\n");
     }
     return 0;
 }