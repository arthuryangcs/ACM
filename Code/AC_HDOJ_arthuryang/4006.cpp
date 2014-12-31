////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-19 13:03:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4006
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
#include<cmath>
#include <queue>
using namespace std;
int n,k;
int cmp(const int &a,const int &b)
{
    return a>b;
}
char s[5];
int num;
int t;
int a[1111111];
int main()
{
    while(~scanf("%d %d",&n,&k))
    {
        num=0;
        while(n--)
        {
            scanf("%s",s);
            if(s[0] == 'Q')
            {
                printf("%d\n",a[0]);
                continue;
            }
            scanf("%d",&t);
            if(num<k)
            {
                a[num++] = t;
                //cout<<num<<endl;
                if(num==k)
                    make_heap(a,a+k,cmp);
            }
            else if(t>a[0])
            {
                pop_heap(a,a+k,cmp);
                a[k-1] = t;
                push_heap(a,a+k,cmp);

            }
        }
    }
    return 0;
}
