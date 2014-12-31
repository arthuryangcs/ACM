////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-22 10:53:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2487
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[101][101];
int f[26];
int l[26][2];
int r[26][2];
int n,m;
void slove()
{
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        //cout<<s[i]<<endl;
    }
    memset(f,0,sizeof(f));
    char tc;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(s[i][j]>='A' && s[i][j]<='Z')
            {
                tc = s[i][j]-'A';
                if(f[tc]==0)
                {
                    f[tc] = 1;
                    l[tc][0] = i;
                    l[tc][1] = j;
                }
                else
                {
                    r[tc][0] = i;
                    r[tc][1] = j;
                }
            }
        }
    }
    for(int k=0;k<26;k++)
    {
        int ff = 0;
        if(!f[k])
            continue;
        if(r[k][0] - l[k][0]<=1 || r[k][1] - l[k][1]<=1)
            continue;
        for(int i=l[k][0];i<=r[k][0];i++)
        {
            for(int j = l[k][1];j<=r[k][1];j++)
            {
                if(i == l[k][0] || i == r[k][0] || j == r[k][1] || j == l[k][1])
                {
                    if(s[i][j]!=k+'A')
                    {
                        ff = 1;
                        break;
                    }
                }
                else
                {
                    if(s[i][j]!='.')
                    {
                        ff = 1;
                        break;
                    }
                }
            }
            if(ff)
                break;
        }
        if(!ff)
        {
            printf("%c",k+'A');
        }
    }
    puts("");
}
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d%d",&n,&m),n+m)
    {
        slove();

    }
    return 0;
}
