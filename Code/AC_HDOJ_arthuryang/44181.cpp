////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-01 16:34:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4418
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:612KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<memory.h>
using namespace std;


int n,m,y,xx,d;
double p[105];
bool vis[210];
double a[210][210];
const double eps = 1e-12;
double x[230];
bool free_x[230];

int sgn(double x)
{
    return (x>eps)-(x<-eps);
}
int gauss(double a[][210],bool l[],double ans[],const int &n)
{
    int ret = 0,r = 0;
    for(int i=0;i<n;i++){
        l[i] = false;
    }
    for(int i=0;i<n;i++){
        for(int j =r;j<n;j++){
            if(fabs(a[j][i]) > eps){
                for(int  k = i;k<=n;k++)
                    swap(a[j][k],a[r][k]);
                break;
            }
        }
        if(fabs(a[r][i])<eps){
            ++ret;
            continue;
        }
        for(int j = 0;j<n;j++){
            if(j!=r && fabs(a[j][i]) > eps){
                double tmp = a[j][i]/a[r][i];
                for(int k = i;k<=n;k++)
                    a[j][k] -= tmp * a[r][k];
            }
        }
        l[i] = true;
        r++;
    }
    for(int i = 0;i<n;i++){
        if(l[i]){
            for(int j = 0;j<n;j++){
                if(fabs(a[j][i]) > eps){
                    ans[i] = a[j][n] / a[j][i];

                }
            }
        }
    }
    return ret==0;
}
int bfs()
{
    queue<int>qiqi;
    qiqi.push(xx);
    vis[xx]=true;
    while(!qiqi.empty())
    {
        int u=qiqi.front();
        qiqi.pop();
        for(int i=1;i<=m;i++)
        {
            int v=(u+i)%n;
            if(sgn(p[i])&&vis[v]==false)
            {
                vis[v]=true;
                qiqi.push(v);
            }
        }
    }
    if(vis[y]||vis[(n-y)%n]) return 1;
    else return 0;
}
void build()
{
        int i,j;
        double sum = 0;
        for (i = 1; i <=m;i++)
        sum += p[i]*i;
        memset(a, 0, sizeof a);
        for (i = 0; i < n; ++i)
        {
            a[i][i] = 1;
            if (!vis[i])
            {
                a[i][n] = 1e9;
                continue;
            }
            if (i==y||i==(n-y)%n)
            {
                a[i][n] = 0;
                continue;
            }
            a[i][n] = sum;
            int now = i;
            for (j = 1; j <=m; ++j)
            {
                now++;
                if (now==n) now = 0;
                a[i][now] -= p[j];
            }
        }
}
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&n,&m,&y,&xx,&d);
        for(int i=1;i<=m;i++)
        {
            int g;
            scanf("%d",&g);
            p[i]=1.0*g/100;
        }
        if(y==xx) {puts("0.00");continue;}
        n=2*(n-1);
        if(d>0) xx=(n-xx)%n;
        memset(vis,false,sizeof(vis));
        if(!bfs()) {puts("Impossible !");continue;}
        build();
        int uu=gauss(a,free_x,x,n);
        if(uu==0)  {puts("Impossible !");continue;}
            printf("%.2lf\n",x[xx]);
    }
}
