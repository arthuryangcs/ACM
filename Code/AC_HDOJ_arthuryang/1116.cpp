////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-26 12:34:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1116
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXN 30
#define _ufind_run(x) for(;p[t=x];x=p[x],p[t]=(p[x]?p[x]:x))
#define _run_both _ufind_run(i);_ufind_run(j)
struct ufind{
	int p[MAXN],t;
	void init(){memset(p,0,sizeof(p));}
	void set_friend(int i,int j){_run_both;p[i]=(i==j?0:j);}
	int is_friend(int i,int j){_run_both;return i==j&&i;}
};
ufind f;
char   a[1111111];
int ru[30];
int chu[30];
int main()
{
    int n;
    int t;
    int i,j;
    int flag=0;
    scanf("%d",&t);
    int fru;
    int fchu;
    while(t--)
    {
        scanf("%d",&n);
        fru=fchu=1;
        f.init();
        flag=0;
        memset(ru,0,sizeof(ru));
        memset(chu,0,sizeof(chu));
        for (int i=0;i<n;i++)
        {
            scanf("%s",a);
            ru[a[0]-'a'+1]++;
            chu[a[strlen(a)-1]-'a'+1]++;
            f.set_friend(a[0]-'a'+1,a[strlen(a)-1]-'a'+1);
        }
        for (i=1;i<30;i++)
        {
            for (j=1;j<30;j++)
            {
                if(ru[i]+chu[i] && ru[j]+chu[j] && !f.is_friend(i,j))
                    flag=1;
            }
        }
        for (i=1;i<30;i++)
        {
            if(ru[i]==chu[i]);
            else if(ru[i]-chu[i]==1 && fru)
            {
                fru=0;
            }
            else if(chu[i]-ru[i]==1 && fchu)
            {
                fchu=0;
            }
            else
                break;
        }
        if(i!=30 || flag)
        {
            printf("The door cannot be opened.\n");
        }
        else
        {
            printf("Ordering is possible.\n");
        }
    }
    return 0;
}