////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-08-10 23:49:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1890
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:10556KB
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

const int INF=0x3f3f3f3f;
const int maxn=1000010;
int n;
int pre[maxn],ch[maxn][2],size[maxn],key[maxn],rev[maxn];
int root,tot1;
int a[maxn];

void NewNode(int &r,int father,int k)
{
    r = k;
    rev[r] = 0;
    pre[r] = father;
    ch[r][0]  = ch[r][1] = 0;
    key[r] = k;
    size[r] = 1;
}

void Update_Rev(int r)
{
    if(r){
        swap(ch[r][0],ch[r][1]);
        rev[r] ^= 1;
    }
}

void Push_Up(int r)
{
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
}

void Push_Down(int r)
{
    if(rev[r]){
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r] = 0;
    }
}

void Build(int &x,int l,int r,int father)
{
    if(l!=r){
        int mid = (l+r)>>1;
        NewNode(x,father,mid);
        Build(ch[x][0],l,mid,x);
        Build(ch[x][1],mid+1,r,x);
        Push_Up(x);
    }
}

void init()
{
    root = 0;
    NewNode(root,0,0);
    size[root] = 0;
    Build(root,1,n+1,0);
}
//旋转，基本固定
void Rotate(int x,int kind)
{
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}
//Splay调整
void Splay(int r,int goal)
{
    Push_Down(r);
    while(pre[r]!=goal)
    {
        if(pre[pre[r]]==goal)
        {
            //这题有反转操作，需要先push_down,在判断左右孩子
            Push_Down(pre[r]);
            Push_Down(r);
            Rotate(r,ch[pre[r]][0]==r);
        }

        else
        {
            //这题有反转操作，需要先push_down,在判断左右孩子
            Push_Down(pre[pre[r]]);
            Push_Down(pre[r]);
            Push_Down(r);
            int y=pre[r];
            int kind=(ch[pre[y]][0]==y);
            //两个方向不同，则先左旋再右旋
            if(ch[y][kind]==r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            //两个方向相同，相同方向连续两次
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    if(goal==0)root=r;
}
int Get_Min(int r)
{
    Push_Down(r);
    while(ch[r][0])
    {
        r=ch[r][0];
        Push_Down(r);
    }
    return r;
}
int Get_Max(int r)
{
    Push_Down(r);
    while(ch[r][1])
    {
        r=ch[r][1];
        Push_Down(r);
    }
    return r;
}

void Remove()
{
    if(ch[root][0] == 0){
        root = ch[root][1];
        pre[root] = 0;
    }
    else{
        int m = Get_Max(ch[root][0]);
        Splay(m,root);
        ch[m][1] = ch[root][1];
        pre[ch[root][1]] = m;
        root = m;
        pre[root] = 0;
        Push_Up(root);
    }
}
pair<int,int > que[maxn];
int main()
{
#ifdef ARTHUR_YANG
freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&n) && n)
    {
        init();
        for(int i = 1;i<=n;i++){
            scanf("%d",&que[i].first);
            que[i].second = i;
        }
        sort(que+1,que+n+1);
        for(int i = 1;i<=n;i++){
            Splay(que[i].second,0);
            Update_Rev(ch[root][0]);
            printf("%d",i+size[ch[root][0]]);
            if(i!=n){
                printf(" ");
            }
            Remove();
        }
        puts("");
    }
    return 0;
}
