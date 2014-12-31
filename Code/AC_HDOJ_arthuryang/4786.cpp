////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-12-01 19:52:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4786
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:3224KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
#define MAXN 111111
int f[100];

struct link
{
    int a,b;
    int f;
}l[111111];

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
int t;
int n,k;
int g(int z)
{
    ufind t;
    t.init();
    int an=0;;
    for (int i=0;i<k;i++)
    {
        if(l[i].f==z && !t.is_friend(l[i].a,l[i].b))
        {
            an++;
            t.set_friend(l[i].a,l[i].b);
        }
    }
    return an;
}

int main()
{
    f[0]=1;
    f[1]=1;
    for (int i=3;i<30;i++)
        f[i] = f[i-1] + f[i-2];
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&k);
        for (int j=0;j<k;j++)
            scanf("%d%d%d",&l[j].a,&l[j].b,&l[j].f);
        ufind t;
        t.init();
        for (int j=0;j<k;j++)
            t.set_friend(l[j].a,l[j].b);
        if(t.count_num(1)!=n)
        {
            printf("Case #%d: No\n",i);
            continue;
        }
        int x = g(1);
        int y = g(0);
        y = n-y-1;
        int j;
        for (j=0;y>f[j];j++);
        if(x>=f[j])
            printf("Case #%d: Yes\n",i);
        else
            printf("Case #%d: No\n",i);
    }
    return 0;
}