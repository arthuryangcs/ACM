////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-06 21:16:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1124KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define N 101000
#define max(a,b) ((a)>(b))?(a):(b)
int number[N];
int set[N];
int Find(int x)
{
     int r=x,i,j;
     while (set[r]!=r)
         r=set[r];
     i=x;
     while (set[i]!=r)
     {
         j=set[i];
         set[i]=r;
         i=j;
     }
     return r;
 }
 void Merge(int x,int y)
 {
     int a,b;
     a=Find(x);
     b=Find(y);
     set[a]=b;
 }
 int main()
 {
     int i,x,y,sets,lines,points,n;
     while (scanf("%d%d",&x,&y),~x||~y)
     {
         n=0;
         lines=0;
         sets=0;
         points=0;
         for(i=0;i<N;i++)
         {
             number[i]=0;
             set[i]=i;
         }
         while (x||y)
         {
             n=max(x,n);
             n=max(y,n);
             number[x]=1;
             number[y]=1;
             lines++;
             Merge(x,y);
             scanf("%d%d",&x,&y);
         }
         for (i=1;i<=n;i++)
         {
             if(number[i]==1)
             {
                 points++;
                 if(set[i]==i)    sets++;
             }                
         }
         if((sets==1&&points==lines+1)||(points==0))
             printf("Yes\n");
         else
             printf("No\n");
     }
     return 0;
 }