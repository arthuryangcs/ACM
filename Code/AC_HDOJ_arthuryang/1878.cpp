////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-12-25 17:03:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1878
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:504KB
//////////////////System Comment End//////////////////
#define MAXN 11111
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int map[MAXN][MAXN];
int v[MAXN][MAXN];
int a[MAXN];
int flag=0;
int n,nn;

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
int num[MAXN];
int main()
{
    int n,m;
    ufind f;
    int x,y;
    int flag=1;
    while(scanf("%d",&n),n)
    {
        f.init();
        flag = 1;
        memset(num,0,sizeof(num));
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            f.set_friend(x,y);
            num[x]++;
            num[y]++;
        }
        if(f.count_num(1)!=n)
            flag=0;
        for (int i =1;i<=n;i++)
            if(num[i]%2==1)
            {
                flag=0;
                break;
            }
        cout<<flag<<endl;
    }
    return 0;
}
