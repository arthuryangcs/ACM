////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-21 14:34:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2485
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:268KB
//////////////////System Comment End//////////////////

//hdu 2485 Destroying the bus stations
//搜索(迭代加深)
//没有反向边

#include <stdio.h>
#include <string.h>


#define N 55
#define INF 1<<30
#define eps 1e-5

int n_node, n_edge, limit, len;//len 记录广搜最短路的长度
int limit_depth;    //记录当前神搜限制的深度
bool success;       //标记是否找到答案


int que[N], road[N][N]; //que广搜时用的队列,road(i, j)表示深度为i时的广搜的最短路
int pre[N]; //pre记录广搜路径
int end[4005], head[N], next[4005], tot;  //邻接表
bool del[N];    //记录被删的点

void add_edge(int from, int to)     //add edge into adjacency list
{
    end[++tot] = to;
    next[tot] = head[from];
    head[from] = tot;
}

bool bfs()   //breadth first search
{
    for(int i = 1; i <= n_node; ++i)
        pre[i] = 0;
    int top = 0, tail = 0;
    que[++top] = 1;
    while(tail < top)
    {
        int now = que[++tail];
        for(int i = head[now]; i != -1; i = next[i])
        {
            int point = end[i];
            if(del[point] == false && pre[point] == 0)
            {
                pre[point] = now;       //记录广搜路径
                que[++top] = point;         //入队
                if(point == n_node)
                    return true;
            }
        }
    }
    return false;
}

void dfs(int dep)   //depth first search
{
    if(success == true)
        return;
    bool find = bfs();   //广搜找最短

    if(find == false)      //找不到最短路了
    {
        success = true;
        return;
    }
    int cnt = 0;    //记录最短路的长度
    //que[top]为最后一个节点,i == 1时就跳出循环，所以没有包括起点和终点
    for(int i = pre[n_node]; i != 1; i = pre[i])
        road[dep][cnt++] = i;
    if(cnt >= limit)
    {
        success = true;
        return;
    }

    if(dep > limit_depth)   //深度大于限制的深度，也就是不能再删点了
        return;

    //不可以删最后一个(i=cnt-2的点)和第一个节点(i=0的点)
    for(int i = cnt - 1; i >= 0; --i)
    {
        int del_point = road[dep][i];
        del[del_point] = true;
        dfs(dep + 1);
        del[del_point] = false;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    bool have[N][N];
    while(scanf("%d%d%d", &n_node, &n_edge, &limit), n_node || n_edge || limit)
    {
        tot = 0;    //邻接表下标
        memset(have, false, sizeof(have));

        for(int i = 0; i <= n_node; ++i)    //初始化
        {
            head[i] = -1;
            del[i] = false;
        }

        for(int i = 0; i < n_edge; ++i)
        {
            int from, to;
            scanf("%d%d", &from, &to);
            if(have[from][to] == false)
            {
                have[from][to] = true;
                add_edge(from, to);
            }
        }

        int m = n_node - 2;
        success = false;
        //迭代加深搜索，限制深度为i，即限制最多删i个点
        for(int i = 0; i <= m; ++i)
        {
            limit_depth = i;
            dfs(1);
            if(success == true)
                break;
        }
        printf("%d\n", limit_depth);
    }
    return 0;
}