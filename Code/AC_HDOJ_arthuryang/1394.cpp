////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-30 13:36:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:843MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define MAX 10000
using namespace std;
int a[MAX];
int b[MAX];
int n;
int sum;
int ma;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ma=sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        b[n-1]=0;
        for (int i=n-2;i>=0;i--)
        {
            b[i]=0;
            for (int j=n-1;j>i;j--)
                if(a[i]>a[j])
                    b[i]++;
            sum+=b[i];
        }
        int tmp=sum;
        for (int i=0;i<n;i++)
        {
            tmp-=2*b[i]-n+1;
            for (int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(a[j]>a[i])
                        b[j]++;
                }
            }
            b[i]=0;
            if(tmp<sum)
                sum=tmp;
            //cout<<tmp<<" ";
        }
        cout<<sum<<endl;
    }
    return 0;
}
