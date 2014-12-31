////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-03 21:29:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3269
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//问题描述：直接说input把
//第一行输入test个数
//接下来是N和T，N代表电脑数，T代表执行了T秒
//接下来时K，S，K代表初始服务器个数，S代表文件数据大小,（注意：如果图中一个客户端下载满了，他也就变成了一个服务器)
//然后是个n*n矩阵，a[i][j]表示i到j传a[i][j]数据每秒
//接下来n行，描述n太电脑的上下线状态按时间升序给出 
//接下来时m条指令，每条指令两个数字，表示第x台电脑从第y秒开始执行下载，按时间非递减给出
//执行下载和传输的两台电脑记住一定要同时在线 
bool online[21][1001];//描述电脑上下线状态
int N,T,K,S;//n是电脑数，T是执行时间,K是服务器个数，S是文件的大小 
bool server[21];//表示是否是服务器
int speed[21][21];//speed[i][j]表示从i到j的单位时间内传输数据量
int m;//m表示下载指令数
vector<int>v[1001];//在第i秒要执行下载命令的电脑 
int download[21];//描述每台电脑下载的数据量
bool start[21];//开始下载的时间     
int main()
{
    int i,j,k,t,x,y,test;
    while(scanf("%d",&test)!=EOF)
    {
          while(test--)
          {                       
                scanf("%d%d",&N,&T);
                for(i=1;i<=N;i++)start[i]=0;      
                for(i=0;i<=T;i++)v[i].clear();                         
                for(i=1;i<=N;i++){server[i]=0;download[i]=0;}                         
                for(i=1;i<=N;i++)for(j=0;j<=T;j++)online[i][j]=0;
                scanf("%d%d",&K,&S);
                for(i=1;i<=K;i++){scanf("%d",&x);server[x]=1;download[x]=S;}
                for(i=1;i<=N;i++)for(j=1;j<=N;j++)scanf("%d",&speed[i][j]);
                for(i=1;i<=N;i++)
                {
                    scanf("%d",&t);
                    for(j=1;j<=t;j++)
                    {
                        scanf("%d%d",&x,&y);
                        for(k=x;k<y;k++)online[i][k]=1;             
                        }             
                    }
                scanf("%d",&m);
                for(i=1;i<=m;i++){scanf("%d%d",&x,&y);v[x].push_back(y);}
                for(i=0;i<=T;i++)
                {
                    for(j=0;j<v[i].size();j++)start[v[i][j]]=1;
                    for(x=1;x<=N;x++)
                    {
                        if(start[x]==0||online[x][i]==0)continue;                 
                        for(k=1;k<=N;k++)if(online[k][i]&&server[k])download[x]+=speed[x][k];                                                    
                        } 
                    for(x=1;x<=N;x++)if(download[x]>=S)server[x]=1;               
                    }                                 
                for(i=1;i<=N;i++)
                {
                    double tmp;
                    if(download[i]>=S)tmp=100;
                    else tmp=100.0*download[i]/S;
                    printf("%d",(int)floor(tmp));cout<<"%"<<endl;             
                    }             
                }
          }
    return 0;
    } 