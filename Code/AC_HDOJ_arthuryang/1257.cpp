////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 16:42:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
int main()
{
    int n,i,j,num,h[1000],max[1000];
    while(~scanf("%d",&n))
    {
        num=0;
        for(i=0;i<n;++i)
        {
            scanf("%d",&h[i]);
            max[i]=1;
        }
        for(i=1;i<n;++i)
            for(j=0;j<i;++j)
            {
                if(h[j]<=h[i]&&max[j]+1>max[i])
                    max[i]=max[j]+1;
                if(num<max[i])
                    num=max[i];
            }
        printf("%d\n",num);
    }
    return 0;
}
