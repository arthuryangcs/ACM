////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-16 17:45:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4300
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1244KB
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

const int maxn = 211111;
const int maxm = 111111;

int n;
char s[maxn];
char t[maxn];
char r[maxn];
int ma[33];
int Next[maxn];
int Ret[maxn];

void ExtendedKMP(char *a,char *b,int M,int N,int *Next,int *ret)
{
    int i,j,k;
    for(j = 0;1+j<M && a[j] == a[1+j];j++);
    Next[1] = j;
    k = 1;
    for(i=2;i<M;i++){
        int len = k + Next[k],L = Next[i-k];
        if(L<len-i){
            Next[i] = L;
        }
        else{
            for(j=max(0,len-i);i+j<M && a[j] == a[i+j];j++);
            Next[i] = j;
            k = i;
        }
    }
    for(j = 0;j<N && j<M && a[j] == b[i];j++);
    ret[0] = j;
    k = 0;
    for(i = 1;i<N;i++){
        int len = k + ret[k],L = Next[i-k];
        if(L< len - i){
            ret[i] = L;
        }
        else{
            for(j = max(0,len-i);j<M && i+j<N && a[j]==b[i+j];j++);
            ret[i] = j;
            k = i;
        }
    }
}

void solve()
{
    scanf("%s%s",s,t);
    for(int i = 0;i<26;i++){
        ma[s[i]-'a'] = i + 'a';
    }
    int len = strlen(t);
    for(int i = 0;i<len;i++){
        r[i] = ma[t[i]-'a'];
    }
    r[len] = 1;
    ExtendedKMP(r,t,len,len,Next,Ret);
    int k;
    for(k = (len+1)/2;k<len;k++){
        if(k+Ret[k]==len){
            break;
        }
    }
    for(int i=0;i<k;i++)printf("%c",t[i]);
    for(int i=0;i<k;i++)printf("%c",ma[t[i]-'a']);
    printf("\n");
}

int main()
{
#ifdef ARTHUR_YANG
    freopen("in.txt","r",stdin);
#endif
    int t;
    while(~scanf("%d",&t)) {
        for(int i = 1;i<=t;i++){
//            printf("Case #%d: ",i);
            solve();
        }
    }
    return 0;
}
