////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-01 17:30:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1800
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<map>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i;
        map<int,int> mp;
        int max=INT_MIN;
        for(i=0;i<n;i++)
        {
            int level;
            scanf("%d",&level);
            mp[level]++;
            if(mp[level]>max)
            {
                max=mp[level];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}