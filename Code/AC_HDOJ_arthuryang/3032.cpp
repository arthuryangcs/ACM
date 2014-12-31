////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-11 16:43:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<iostream>
#include <cstdio>
#include<string.h>
using namespace std;
int main()
{
    int t , n, x;
    int ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            if(x%4==0)  ans^=(x-1);
            else if(x%4==1 || x%4==2)  ans^=x;
            else ans^=(x+1);
        }
        if(ans!=0)
            printf("Alice\n");
        else
        printf("Bob\n");
    }
    return 0;
}
