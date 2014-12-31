////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-11-30 12:27:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4770
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include<cstdio>  
#include<algorithm>  
#include<iostream>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#include<vector>  
#include<queue>  
using namespace std;  
typedef long long ll;  
/*  define */  
  
#define sf(a) scanf("%d",&a)  
#define sfs(a) scanf("%s",a)  
#define sfI(a) scanf("%I64d",&a)  
#define pf(a) printf("%d\n",a)  
#define pfI(a) printf("%I64d\n",a)  
#define rep(i,a,b) for(int i=(a);i<=(b);i++)  
#define repd(i,a,b) for(int i=(a);i>=(b);i--)  
#define rep1(i,a,b) for(int i=(a);i<(b);i++)  
#define clr(a) memset(a,0,sizeof(a))  
#define pfk  printf("fuck\n")  
  
/*  define */  
struct node{  
    int x,y;  
}lamp[20];  
int cnt,res,special,n,m,ans;  
bool li[250][250];  
char mat[250][250];  
void dfs(int c,int step){  
    int x=lamp[c].x;  
    int y=lamp[c].y;  
    if(c>cnt){  
        int f=1;  
        rep(i,1,cnt){  
            x=lamp[i].x;y=lamp[i].y;  
            if(li[x][y]==0){  
                f=0;  
                break;  
            }  
        }  
        if(f==1) res=min(res,step);  
        return ;  
    }  
    if(c==special) {dfs(c+1,step); return ;}  
    if(mat[x-1][y]=='#'||mat[x][y+1]=='#') {  
        dfs(c+1,step);  
        return ;  
    }  
    dfs(c+1,step);  
    bool o1=li[x-1][y],o2=li[x][y+1],o3=li[x][y];  
    li[x-1][y]=1;li[x][y+1]=1;li[x][y]=1;  
    dfs(c+1,step+1);  
    li[x-1][y]=o1,li[x][y+1]=o2,li[x][y]=o3;  
}  
int main(){  
    while(scanf("%d%d",&n,&m)){  
        if(n+m==0) return 0;  
        cnt=0;  
        bool f=0;  
        clr(mat);  
        rep(i,1,n){  
            getchar();  
            rep(j,1,m){  
                scanf("%c",&mat[i][j]);  
                if(mat[i][j]=='.'){  
                    f=1;  
                    lamp[++cnt].x=i;  
                    lamp[cnt].y=j;  
                }  
            }  
        }  
        ans=999999;  
        rep(i,1,cnt){  
            special=i;  
            int x=lamp[i].x,y=lamp[i].y;  
            if(mat[x-1][y]!='#'&&mat[x][y+1]!='#'){  
                clr(li);  
                li[x-1][y]=li[x][y+1]=li[x][y]=1;  
                res=999999+1;  
                dfs(1,1);  
                ans=min(ans,res);  
            }  
            if(mat[x][y+1]!='#'&&mat[x+1][y]!='#'){  
                clr(li);  
                li[x][y+1]=li[x+1][y]=li[x][y]=1;  
                res=999999+1;  
                dfs(1,1);  
                ans=min(ans,res);  
            }  
            if(mat[x+1][y]!='#'&&mat[x][y-1]!='#'){  
                clr(li);  
                li[x+1][y]=li[x][y-1]=li[x][y]=1;  
                res=999999+1;  
                dfs(1,1);  
                ans=min(ans,res);  
            }  
            if(mat[x][y-1]!='#'&&mat[x-1][y]!='#'){  
                clr(li);  
                li[x][y-1]=li[x-1][y]=li[x][y]=1;  
                res=999999+1;  
                dfs(1,1);  
                ans=min(ans,res);  
            }  
        }  
        if(f==0) puts("0");  
        else if(ans==999999) puts("-1");  
        else pf(ans);  
    }  
    return 0;  
}  