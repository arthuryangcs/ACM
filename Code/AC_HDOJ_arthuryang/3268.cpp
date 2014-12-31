////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-05-29 11:50:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3268
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <iostream> 
#include <queue> 
#include <cstdio> 
#include <map> 
using namespace std; 
   
const int maxn=30; 
   
struct edge{ 
    int u,v,w,next; 
    edge(int u0=0,int v0=0,int w0=0,int next0=0){ 
        u=u0;v=v0;w=w0;next=next0; 
    } 
}e[maxn*maxn]; 
   
int n,head[maxn],cnt,price[maxn],from,dist[maxn]; 
bool visited[maxn]; 
   
void initial(){ 
    from=0;cnt=0; 
    for(int i=0;i<=n;i++){ 
        visited[i]=false; 
        head[i]=-1;dist[i]=200000000; 
    } 
} 
   
void adde(int u,int v,int w){ 
    e[cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt++; 
} 
   
void input(){ 
    int m,x,y,z; 
    for(int i=0;i<n;i++){ 
        cin>>x>>y; 
        price[x]=y; 
        adde(from,x,y-1); 
    } 
    for(int i=1;i<=n;i++){ 
        for(int j=i+1;j<=n;j++){ 
            if(price[i]==price[j]){ 
                adde(i,j,0); 
                adde(j,i,0); 
            } 
        } 
    } 
    cin>>m; 
    while(m-- >0){ 
        cin>>x>>y>>z; 
        adde(x,y,z); 
    } 
} 
   
void spfa(){ 
    queue <int> q; 
    int s=from,d; 
    dist[from]=0; 
    q.push(s); 
    visited[s]=true; 
    while(!q.empty()){ 
        s=q.front(); 
        q.pop(); 
        for(int i=head[s];i!=-1;i=e[i].next){ 
            d=e[i].v; 
            if(dist[d]>dist[s]+e[i].w){ 
                dist[d]=dist[s]+e[i].w; 
                if(!visited[d]){ 
                    visited[d]=true; 
                    q.push(d); 
                } 
            } 
        } 
        visited[s]=false; 
    } 
       
} 
   
void computing(){ 
    int ans=0; 
    spfa(); 
    for(int i=1;i<=n;i++){ 
        cout<<i<<" "<<dist[i]<<endl; 
    } 
    for(int i=1;i<=n;i++){ 
        bool flag=true; 
        for(int j=1;j<=n && flag;j++){ 
            for(int t=j+1;t<=n && flag;t++){ 
                if(i==j || j==t || i==t) continue; 
                if(dist[i]==dist[j]+dist[t]){ 
                    ans++; 
                    flag=false; 
                } 
            } 
        } 
    } 
    cout<<ans<<endl; 
} 
   
int main(){ 
    int t; 
    cin>>t; 
    while(t-- >0){ 
        cin>>n; 
        initial(); 
        input(); 
        computing(); 
    } 
    return 0; 
}  