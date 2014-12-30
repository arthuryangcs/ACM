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
    int fin(char *s)
    {
        int len = strlen(s);
        int rt = 0;
        int ans = 0;
        int t;
        for(int i = 0;i<len;i++){
            while(rt!=-1 && !ch[rt][s[i]-'a']){
                 rt = fail[rt];
            }
            if(rt == -1){
                rt = 0;
                continue;
            }
            rt = ch[rt][s[i]-'a'];
            t = rt;
            //根据题意修改一下信息。
            while(t!=-1 && is[t]!=-1){
                if(is[t]>0){
                    ans+=is[t];
                }
                is[t] = -1;
                t = fail[t];
            }
        }
        return ans;
    }
};
