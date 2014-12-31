////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-07 00:13:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:26680KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
int len;
char str[60];
char text[1000010];

struct node
{
    int fail;
    int count;
    int nxt[26];
    void init()
    {
        fail=-1;
        count = 0;
        memset(nxt,-1,sizeof(nxt));
    }
} num[500010];

void insert(char *str)
{
    int i =0;
    int p =0;
    while(str[i])
    {
        int ind = str[i]-'a';
        if(num[p].nxt[ind]==-1)
        {
            num[p].nxt[ind] = ++len;
            num[len].init();
        }
        p = num[p].nxt[ind];
        ++i;
    }
    ++num[p].count;
}

void buildAC()
{
    int i;
    queue<int> cq;
    for(i=0; i<26; ++i)
        if(num[0].nxt[i]!=-1)
        {
            num[num[0].nxt[i]].fail = 0;
            cq.push(num[0].nxt[i]);
        }
    int p;
    while(!cq.empty())
    {
        p = cq.front();
        cq.pop();
        for(i=0; i<26; ++i)
            if(num[p].nxt[i]!=-1)
            {
                cq.push(num[p].nxt[i]);
                int tmp = num[p].fail;
                while(tmp>0&&num[tmp].nxt[i]==-1)
                    tmp = num[tmp].fail;
                if(num[tmp].nxt[i]!=-1)
                    num[num[p].nxt[i]].fail = num[tmp].nxt[i];
                else num[num[p].nxt[i]].fail = 0;
            }
    }
    return;
}
int query(char *str)
{
    int ret(0);
    int i = 0;
    int p = 0;
    while(str[i])
    {
        int ind = str[i]-'a';
        while(p>0&&num[p].nxt[ind]==-1)
            p = num[p].fail;
        if(num[p].nxt[ind]!=-1)
            p = num[p].nxt[ind];
        else p = 0;
        int tmp = p;
        while(tmp!=0&&num[tmp].count!=-1)
        {
            ret+=num[tmp].count;
            num[tmp].count = -1;
            tmp = num[tmp].fail;
        }
        ++i;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        num[0].init();
        len = 0;
        while(n--)
        {
            scanf("%s",str);
            insert(str);
        }
        buildAC();
        scanf("%s",text);
        printf("%d\n",query(text));
    }
    return 0;
}