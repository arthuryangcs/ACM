////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-02 17:04:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3887
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:7068KB
//////////////////System Comment End//////////////////
#pragma comment(linker,"/STACK:100000000,100000000")
#include<cstdio>
#include<cstring>
const int maxn = 100010;
struct EDGE{
    int  v,next;
}edge[maxn*2];
int head[maxn],ans[maxn],p[maxn];
int tot;
void add(int a,int b){
    edge[tot].v=a;    edge[tot].next=head[b];head[b]=tot++;
    edge[tot].v=b;  edge[tot].next=head[a];head[a]=tot++;
}
int c[maxn];
int lowbit(int x){
    return x&-x;
}
void update(int x,int d){
    for(;x<maxn;c[x]+=d,x+=lowbit(x));
}
int sum(int x){
    int ans=0;
    for(;x>0;ans+=c[x],x-=lowbit(x));
    return ans;
}
void dfs(int x,int fa){
    p[x]=sum(x-1);
    for(int i=head[x];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v!=fa){
            update(v,1);
            dfs(v,x);
        }
    }
    ans[x]=sum(x-1)-p[x];
}
int main(){
    int n,root,i,j,a,b;
    while(scanf("%d%d",&n,&root),(n||root)){
        tot=0;
        memset(head,-1,sizeof(head));
        memset(c,0,sizeof(c));
        for(i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        dfs(root,root);
        for(i=1;i<n;i++)    printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}