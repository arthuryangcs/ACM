////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-10-14 21:05:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1576
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
const int k=9973;
int exgcd(int a,int b,int &x,int &y)
{
 if(b==0)
 { x=1;y=0;return a;}
 int r=exgcd(b,a%b,x,y);
 int t=x;
     x=y;
  y=t-a/b*y;
  return r;
}
int main()
{
 int T,n,b;
    scanf("%d",&T);
 while(T--)
 {
  scanf("%d%d",&n,&b);
  int x,y;
  exgcd(b,k,x,y);
  x*=n;
  if(x<0)
  {
   int t1=-x;
   int t2=t1%k;
   x=k-t2;
  }
  printf("%d\n",x%k);
 }
 return 0;
}
