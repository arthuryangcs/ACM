////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-02 15:53:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4545
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int n;
char s[1111];
char ss[1111];
bool g[111][111];

void slove()
{
    memset(g,0,sizeof(g));
    for(int i=0;i<30;i++)
        g[i][i] = true;
    scanf("%s",s);
    scanf("%s",ss);
    int m;
    scanf("%d",&m);
    char t[4],tt[4];
    for(int i=0;i<m;i++)
    {
        scanf("%s%s",t,tt);
        g[t[0]-'a'][tt[0]-'a'] = true;
    }
    int len = strlen(s);
    int lenn = strlen(ss);
    int i=0,j=0;
    for(;i<len;i++){
        for(;j<lenn;j++)
            if(g[ss[j]-'a'][s[i]-'a'])
                break;
        if(j<lenn)
            j++;
        else
            break;
    }
    if(i==len)
        puts("happy");
    else
        puts("unhappy");
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++){
            printf("Case #%d: ",i);
            slove();
        }
    }
    return 0;
}
