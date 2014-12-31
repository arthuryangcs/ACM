////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-06-18 19:51:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3264
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define INF 2147483647
#define N 25
#define PI 3.141592653
#define EPS 1e-8
struct point
{
    double x;
    double y;
}p[N];
double r[N];
int n;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double interarea(point a,double ra,point b,double rb)   //求圆相交面积的模板 重点
{
    double ans=0;
    double d=dis(a,b);
    double temp;
    if(ra<rb)
    {
        temp=ra;
        ra=rb;
        rb=temp;
    }
    if(d>=ra+rb)return 0;        //相离
    if(d<=ra-rb)return PI*rb*rb;         //内含
    double angle1=acos((ra*ra+d*d-rb*rb)/2.0/ra/d);
    double angle2=acos((rb*rb+d*d-ra*ra)/2.0/rb/d);
    ans-=d*ra*sin(angle1);
    ans+=angle1*ra*ra+angle2*rb*rb;
    return ans;
}

double did(int x)
{
    int f=1;
    double l = 0,rr = 1e5,mid;
    while(rr-l>1e-8)
    {
        f = 1;
        mid = (l+rr)/2;
        for(int i = 0;i<n;i++)
        {
            //cout<<mid<<" "<<interarea(p[i],r[i],p[x],mid)<<endl;
            if(2*interarea(p[i],r[i],p[x],mid)>=PI*r[i]*r[i])
                continue;
            else
            {
                l = mid;
                f = 0;
                break;
            }
        }
        if(f)
        rr = mid;
    }
    return (l+rr)/2;
}

void slove()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%lf%lf%lf",&p[i].x,&p[i].y,&r[i]);
    }
    double ans = 1e5,t;
    for(int i = 0;i<n;i++)
    {
        ans = min(ans,did(i));
    }
    printf("%.4lf\n",ans);
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d",&t))
    {
        while(t--)
            slove();
    }
}
