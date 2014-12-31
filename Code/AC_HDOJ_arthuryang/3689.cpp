////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-28 14:19:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3689
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:532KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 22;
const int maxm = 111111;

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
        is[rt]++;  //允许重复关键字，分别计算。不允许可改为is[rt]=1;
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
                }
            }
        }
    }
};


int n,m;
Tree tree;
double a[33];
int is[33];
int num = 0;
char s[33];
double dp[1111][33];
int fail[33][33];
void solve()
{
    tree.init();
    num = 0;
    double t;
    for(int i = 0;i<n;i++){
        scanf("%s %lf",s,&t);
        is[num] = s[0]-'a';
        a[num++] = t;
    }
    scanf("%s",s);
    tree.insert(s);
    tree.make_fail();
    memset(dp,0,sizeof(dp));
    dp[0][0] = 100.0;
    int rt;
    for(int i = 0;i<num;i++){
        fail[tree.now-1][i] = tree.now-1;
    }
    for(int i = 0;i<num;i++){
        for(int j = 0;j<tree.now-1;j++){
            rt = j;
            while(rt != -1 && tree.ch[rt][is[i]]==0){
                rt = tree.fail[rt];
            }
            if(rt == -1){
                rt = 0;
            }
            else{
                rt = tree.ch[rt][is[i]];
            }
            fail[j][i] = rt;
        }
    }
    for(int k = 1;k<=m;k++){
        for(int i = 0;i<num;i++){
            for(int j = 0;j<tree.now;j++){
                rt = fail[j][i];
                dp[k][rt] += a[i]*dp[k-1][j];
            }
        }
    }
    printf("%.2lf",dp[m][tree.now-1]);
    puts("%");
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d%d",&n,&m),n+m) {
//        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
//        }
    }
    return 0;
}
