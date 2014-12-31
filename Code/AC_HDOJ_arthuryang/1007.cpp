////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-25 21:03:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1007
////Problem Title: 
////Run result: Accept
////Run time:1890MS
////Run memory:3496KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
 
typedef struct Point{
    double x;
    double y;
} Point;
Point X[100002],Y[100002];
 
double dist(Point u,Point v)
{
    return sqrt((u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y));
}
 
 
bool cmpx(Point u,Point v)
{
    return u.x < v.x;
}
 
bool compy(Point u,Point v)
{
    return u.y < v.y;
}
 
double min ( double a , double b )
{
 return a<b?a:b;
}
 
double clost(int l,int r)
{
    if(l+1==r)
        return dist(X[l],X[r]);
    else if(l+2==r) {
    double tem1 = dist(X[l],X[l+1]);
    double tem2 = dist(X[l],X[r]);
    double tem3 = dist(X[l+1],X[r]);
    double mintemp=min(tem1,min(tem2,tem3));
    return mintemp;
    }
    else {
    int i,j,mid,count=0;
    double mini;
    mid = (l +r) /2;
    mini = min(clost(l,mid),clost(mid+1,r));
    for(i=l; i <= r; i++)
    {
        if(fabs(X[i].x-X[mid].x) <= mini)
        Y[count++]=X[i];
    }
    sort(Y,Y+count,compy);
    for(i=0; i < count; i++)
    {
        for(j=i+1; j < count; j++)
        {
        if(Y[j].y - Y[i].y >= mini)
            break;
        else
        {
            if(dist(Y[j],Y[i]) < mini)
            mini=dist(Y[j],Y[i]);
        }
        }
    }
    return mini;
    }
}
 
int main()
{
 
    int i,n;
    while(cin >> n)
    {
        if(n==0) break;
 
        for(i=0; i < n; i++)
        {
           scanf("%lf%lf",&X[i].x,&X[i].y);
        }
        sort(X,X+n,cmpx);
        printf("%.2lf\n",clost(0,n-1)/2.0);
    }
    return 0;
}