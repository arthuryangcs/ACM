////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-21 15:19:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:28424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 600000;

struct Tree
{
    int ch[maxn][27];
    int is[maxn];
    int fail[maxn];
    int que[maxn];
    int now;
    void init()
    {
        now = 0;
        memset(ch[now],0,sizeof(ch[now]));
        is[now] = 0;
        now++;
    }
    void insert(char *s)
    {
        int rt = 0;
        int len = strlen(s);
        for(int i = 0;i<len;i++){
            if(ch[rt][s[i]-'a']){
                rt = ch[rt][s[i]-'a'];
            }
            else{
                ch[rt][s[i]-'a'] = now;
                rt = now++;
                memset(ch[rt],0,sizeof(ch[rt]));
                is[rt] = 0;
            }
        }
        is[rt]++;
    }
    void make_fail()
    {
        int x,t;
        int to = 0,en = 0;
        que[to++] = 0;
        fail[0] = -1;
        while(to!=en){
            x = que[en++];
            for(int i = 0;i<26;i++){
                if(ch[x][i]){
                    que[to++] = ch[x][i];
                    t = fail[x];
                    while(t!=-1 && !ch[t][i]){
                        t = fail[t];
                    }
                    if(t==-1){
                        fail[ch[x][i]] = 0;
                    }
                    else{
                        fail[ch[x][i]] = ch[t][i];
                    }
                    //cout<<i<<t<<fail[ch[x][i]]<<endl;
                }
            }
        }
    }
    int fin(char *s)
    {
        int len = strlen(s);
        int rt = 0;
        int ans = 0;
        int t;
        for(int i = 0;i<len;i++){
            if(rt == -1){
                rt = 0;
                continue;
            }

            if(ch[rt][s[i]-'a']){
                rt = ch[rt][s[i]-'a'];
                t = rt;
                while(t!=-1 && is[t]!=-1){
                    if(is[t]>0){
                        ans+=is[t];
                    }
                    is[t] = -1;
                    t = fail[t];
                }
            }
            else{
                i--;
                rt = fail[rt];
            }
        }
        return ans;
    }
};

char s[1100000];
Tree tree;

void solve()
{
    tree.init();
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",s);
        tree.insert(s);
    }
    tree.make_fail();
    scanf("%s",s);
    printf("%d\n",tree.fin(s));
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif // ARTHUR_YANG
    int t;
    while(~scanf("%d",&t)){
        for(int i = 1;i<=t;i++){
            //printf("Case #%d: ",i);
            solve();
        }
    }
    return 0;
}
