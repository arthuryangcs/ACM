////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 15:21:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:660KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;
int hash[111111];
int main()
{
    int n;
    int t;
    int y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        y=1;
        memset(hash,0,sizeof(hash));
        hash[1]=1;
        if(n<0)
        {
            n=-n;
            printf("-");
        }
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        printf("0.");
        while(y)
        {
            y*=10;
            printf("%d",y/n);
            y%=n;
            if(hash[y])
            break;
            hash[y]=1;
        }
        printf("\n");
    }
    return 0;
}
