////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-22 23:23:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4750
////Problem Title: 
////Run result: Accept
////Run time:4187MS
////Run memory:7464KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <functional>
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
#define MAXN 11000
class ufind
{
private:
    int num[MAXN];
    int father[MAXN];
public:
    void init()
    {
        int i;
        for(i=0; i<MAXN; i++)
        {
            father[i]=i;
            num[i]=1;
        }
    }
    int count_num(int x)
    {
        return num[find_set(x)];
    }
    int find_set(int x)
    {
        if(father[x]!=x)
        {
            father[x]=find_set(father[x]);
        }
        return father[x];
    }
    void set_friend(int x,int y)
    {
        int a,b;
        a=find_set(x);
        b=find_set(y);
        if(a==b)
            return;
        if(num[a]>num[b])
        {
            father[b]=a;
            num[a]+=num[b];
        }
        else
        {
            father[a]=b;
            num[b]+=num[a];
        }
    }
    bool is_friend(int x,int y)
    {
        return find_set(x) == find_set(y);
    }
};

void fre()
{
    freopen("in.txt","r",stdin);
}

int n,m,p;
struct qq
{
    int x;
    int n;
    int ans;
}q[100001];

int cmp1(const qq &a,const qq &b)
{
    return a.x<b.x;
}

int cmp2(const qq &a,const qq &b)
{
    return a.n<b.n;
}

struct node
{
    int x,y,n;
}no[555000];

int cmp3(const node &a,const node &b)
{
    return a.n<b.n;
}

int main()
{
    //fre();
    while(~scanf("%d%d",&n,&m))
    {
        for (int i=0;i<m;i++)
            scanf("%d%d%d",&no[i].x,&no[i].y,&no[i].n);
        sort(no,no+m,cmp3);
        scanf("%d",&p);
        for (int i=0;i<p;i++)
        {
            scanf("%d",&q[i].x);
            q[i].n = i;
            q[i].ans = 0;
        }
        sort(q,q+p,cmp1);
        ufind fr;
        fr.init();
        int now = 0;
        int t = 0;
        for (int i=0;i<m;i++)
        {
            while(now<p  && q[now].x<=no[i].n)
            {
                q[now++].ans = t;
            }
            if(fr.is_friend(no[i].x,no[i].y))
                continue;
            t += 2*fr.count_num(no[i].x)*fr.count_num(no[i].y);
            fr.set_friend(no[i].x,no[i].y);
        }
        for (int i=now;i<p;i++)
        {
            q[i].ans = t;
        }
        sort(q,q+p,cmp2);
        //cout<<t<<endl;
        for (int i=0;i<p;i++)
        {
            //cout<<q[i].x<<q[i].n<<endl;
            printf("%d\n",t - q[i].ans);
        }
    }
    return 0;
}
