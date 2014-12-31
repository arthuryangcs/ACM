////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-25 14:40:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1181
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int map[100][100];
int v[26];
char t[10000];
int x,y;
int n;

int dfs(int s)
{
    v[s]=1;
    int i=0;
    for (int i=0;i<26;i++)
    {
        if(v[i]==0 && map[s][i] && i!=s )
        {
            if(i=='m'-'a')
            {
                return 1;
            }
            else if (dfs(i)==1)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    memset(map,0,sizeof(map));
    memset(v,0,sizeof(v));
    n=0;
    while(scanf("%s",t)!=EOF)
    {
        if(t[0]=='0')
        {
            if(dfs(1))
            {
                printf("Yes.\n");
            }
            else
            {
                printf("No.\n");
            }
            memset(map,0,sizeof(map));
            memset(v,0,sizeof(v));
            n=0;
        }
        else
        {
            x=t[0]-'a';
            y=t[strlen(t)-1]-'a';
            map[x][y]=1;
        }
    }
    return 0;
}
