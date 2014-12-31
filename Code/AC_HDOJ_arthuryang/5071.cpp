////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-10-29 18:34:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5071
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:500KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int LL;

const int INF=0x3f3f3f3f;

const int HEAD=0;
const int TAIL=6400;

struct CHART
{
    int pro,front,back;
    LL w;
}chat[6500];

int n,x,id;
int alwayson;
set<int> pc;
char cmd[50];

void init()
{
    id=1;pc.clear();alwayson=-1;
    memset(chat,0,sizeof(chat));
    chat[HEAD].front=HEAD; chat[HEAD].back=TAIL;
    chat[TAIL].front=HEAD; chat[TAIL].back=TAIL;
    chat[HEAD].pro=-INF-1; chat[TAIL].pro=-INF-1;
}

void Add(int u)
{
    if(pc.count(u))
    {
        puts("same priority.");
        return ;
    }
    pc.insert(u);
    chat[id].w=0; chat[id].pro=u;
    chat[id].front=chat[TAIL].front;
    chat[id].back=TAIL;
    chat[chat[TAIL].front].back=id;
    chat[TAIL].front=id;
    id++;
    puts("success.");
}

void Close(int u)
{
    if(pc.count(u)==0)
    {
        puts("invalid priority.");
        return ;
    }
    pc.erase(u);
    if(alwayson==u) alwayson=-1;
    int pos=HEAD;
    for(pos=HEAD;pos!=TAIL;pos=chat[pos].back)
    {
        if(chat[pos].pro==u) break;
    }
    int bc=chat[pos].back;
    int ft=chat[pos].front;
    chat[bc].front=ft;
    chat[ft].back=bc;
    printf("close %d with %I64d.\n",chat[pos].pro,chat[pos].w);
}

void Chat(int w)
{
    if(chat[HEAD].back==TAIL)
    {
        puts("empty.");
        return ;
    }
    puts("success.");
    int u=-1;
    if(alwayson!=-1) u=alwayson;
    else u=chat[chat[HEAD].back].pro;
    int pos=HEAD;
    for(pos=HEAD;pos!=TAIL;pos=chat[pos].back)
    {
        if(chat[pos].pro==u) break;
    }
    chat[pos].w+=w;
}

void Rotate(int x)
{
    if(x<1||x>pc.size())
    {
        puts("out of range.");
        return ;
    }
    puts("success.");
    int pos=HEAD,i=0;
    for(pos=HEAD;i<x&&pos!=TAIL;pos=chat[pos].back,i++) ;
    ///split
    int bc=chat[pos].back;
    int ft=chat[pos].front;
    chat[bc].front=ft;
    chat[ft].back=bc;
    ///merge
    chat[pos].front=HEAD;
    chat[pos].back=chat[HEAD].back;
    chat[chat[HEAD].back].front=pos;
    chat[HEAD].back=pos;
}

void Prior()
{
    if(chat[HEAD].back==TAIL)
    {
        puts("empty.");
        return ;
    }
    puts("success.");
    int pos=HEAD;
    int mxp=HEAD;
    for(pos=HEAD;pos!=TAIL;pos=chat[pos].back)
    {
        if(chat[pos].pro>chat[mxp].pro)
        {
            mxp=pos;
        }
    }
    pos=mxp;
    ///split
    int bc=chat[pos].back;
    int ft=chat[pos].front;
    chat[bc].front=ft;
    chat[ft].back=bc;
    ///merge
    chat[pos].front=HEAD;
    chat[pos].back=chat[HEAD].back;
    chat[chat[HEAD].back].front=pos;
    chat[HEAD].back=pos;
}

void Choose(int u)
{
    if(pc.count(u)==0)
    {
        puts("invalid priority.");
        return ;
    }
    puts("success.");
    int pos=HEAD;
    for(pos=HEAD;pos!=TAIL;pos=chat[pos].back)
    {
        if(chat[pos].pro==u) break;
    }
    ///split
    int bc=chat[pos].back;
    int ft=chat[pos].front;
    chat[bc].front=ft;
    chat[ft].back=bc;
    ///merge
    chat[pos].front=HEAD;
    chat[pos].back=chat[HEAD].back;
    chat[chat[HEAD].back].front=pos;
    chat[HEAD].back=pos;
}

void Top(int u)
{
    if(pc.count(u)==0)
    {
        puts("invalid priority.");
        return ;
    }
    puts("success.");
    alwayson=u;
}

void Untop()
{
    if(alwayson==-1)
    {
        puts("no such person.");
        return ;
    }
    alwayson=-1;
    puts("success.");
}

void saybyebye()
{
    if(alwayson!=-1)
    {
        int p=HEAD;
        for(p=HEAD;p!=TAIL;p=chat[p].back)
        {
            if(chat[p].pro==alwayson) break;
        }
        if(chat[p].w) printf("Bye %d: %I64d\n",chat[p].pro,chat[p].w);
    }
    int pos=HEAD;
    for(pos=chat[HEAD].back;pos!=TAIL;pos=chat[pos].back)
    {
        if(chat[pos].pro!=alwayson&&chat[pos].w)
            printf("Bye %d: %I64d\n",chat[pos].pro,chat[pos].w);
    }
}

int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif

    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        init();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",cmd);
            printf("Operation #%d: ",i+1);
            if(strcmp(cmd,"Add")==0)
            {
                int u; scanf("%d",&u);
                Add(u);
            }
            else if(strcmp(cmd,"Close")==0)
            {
                int u; scanf("%d",&u);
                Close(u);
            }
            else if(strcmp(cmd,"Chat")==0)
            {
                int u; scanf("%d",&u);
                Chat(u);
            }
            else if(strcmp(cmd,"Rotate")==0)
            {
                int u; scanf("%d",&u);
                Rotate(u);
            }
            else if(strcmp(cmd,"Prior")==0)
            {
                Prior();
            }
            else if(strcmp(cmd,"Choose")==0)
            {
                int u; scanf("%d",&u);
                Choose(u);
            }
            else if(strcmp(cmd,"Top")==0)
            {
                int u; scanf("%d",&u);
                Top(u);
            }
            else if(strcmp(cmd,"Untop")==0)
            {
                Untop();
            }
        }
        saybyebye();
    }
    return 0;
}
