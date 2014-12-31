////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-01 17:08:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:4140KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int a[1000001];
int n;
int t;
long long sum;
int main()
{
    int tmp;
    int flag;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            flag=0;
            sum=0;
            memset(a,0,sizeof(a));
            scanf("%d",&n);
            for (int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                sum+=a[i];
            }
            for (int i=0;i<n;i++)
            {
                if(a[i]>(sum+1)/2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
}
