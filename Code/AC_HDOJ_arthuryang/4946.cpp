////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-21 12:58:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4946
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 555;
const int maxm = 40005;

struct aaa
{
    int x,y,v,num,cf;
    friend bool operator <(const aaa &a,const aaa &b){
        if(a.x == b.x){
            return a.y<b.y;
        }
        else{
            return a.x<b.x;
        }
    }
}a[maxn];
int n,nn;
int ans[maxn];
struct point
{
    int x,y,num,cf;
};
point list[maxn];
int stack[maxn],top;

int cross(point p0,point p1,point p2) //计算叉积  p0p1 X p0p2
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(point p1,point p2)  //计算 p1p2的 距离
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
bool cmp(point p1,point p2) //极角排序函数 ， 角度相同则距离小的在前面
{
    int tmp=cross(list[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;
    else return false;
}
void init(int n) //输入，并把  最左下方的点放在 list[0]  。并且进行极角排序
{
    int i,k;
    point p0;
    list[0].x = a[0].x;
    list[0].y = a[0].y;
    list[0].cf = a[0].cf;
    list[0].num = a[0].num;
    p0.x=list[0].x;
    p0.y=list[0].y;
    p0.cf = list[0].cf;
    p0.num = list[0].num;
    k=0;
    for(i=1;i<n;i++)
    {
        list[i].x = a[i].x;
        list[i].y = a[i].y;
        list[i].cf = a[i].cf;
        list[i].num = a[i].num;
        if( (p0.y>list[i].y) || ((p0.y==list[i].y)&&(p0.x>list[i].x)) )
        {
            p0.x=list[i].x;
            p0.y=list[i].y;
            p0.cf=list[i].cf;
            p0.num = list[i].num;
            k=i;
        }
    }
    list[k]=list[0];
    list[0]=p0;

    sort(list+1,list+n,cmp);
    for(i = n-1;i>0;i--){
        if(cross(list[0],list[i-1],list[i])!=0)
            break;
    }

    if(i!=0 && i!=n-1){
        reverse(list+i,list+n);
    }
}

void graham(int n)
{
    int i;
    if(n==1) {top=0;stack[0]=0;}
    else
    {
        for(i=0;i<=1;i++) stack[i]=i;
        top=1;

        for(i=2;i<n;i++)
        {
            while(top>0&&cross(list[stack[top-1]],list[stack[top]],list[i])<0) top--;
            top++;
            stack[top]=i;
        }
    }
}
void solve()
{
    nn = n;
    int ma = 1;
    for(int i = 0;i<n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        ma = max(ma,a[i].v);
        a[i].num = i+1;
        a[i].cf = 0;
    }
    sort(a,a+n);
    int num = 0;
    for(int i = 0;i<n;i++){
        if(a[i].v == ma){
            a[num].x = a[i].x;
            a[num].y = a[i].y;
            a[num].v = a[i].v;
            a[num].num = a[i].num;
            num++;
        }
    }
    memset(ans,0,sizeof(ans));
    n = 0;
    for(int i = 0;i<num;i++){
        a[n].x = a[i].x;
        a[n].y = a[i].y;
        a[n].v = a[i].v;
        a[n].num = a[i].num;
        n++;
        while(i<num-1 && a[n-1].x==a[i+1].x && a[n-1].y==a[i+1].y){
            a[n-1].cf = 1;
            i++;
        }
    }
    if(n!=0){
        init(n);
        graham(n);
        for(int i = 0;i<=top;i++){
            if(!list[stack[i]].cf)
                ans[list[stack[i]].num] = 1;
        }
    }

    for(int i = 1;i<=nn;i++){
        printf("%d",ans[i]);
    }
    puts("");
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t=1;
    while(~scanf("%d",&n),n){
        printf("Case #%d: ",t++);
        solve();
    }
    return 0;
}