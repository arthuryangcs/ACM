////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-25 12:43:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:412KB
//////////////////System Comment End//////////////////
/*
题目描述：无界背包问题。给定一个背包的容量W以及n种物品的价值p[i]及重量w[i]，求使背包恰好装满
的物品价值的最大值，如不存在，则输出impossible。

HDOJ 1114

*/

#include<iostream>
#include<vector>
#include<assert.h>
#include<cstring>
using namespace std;

const int N = 500+10;

struct Coin
{
    int price;
    int weight;
};

Coin coin[N];
int f[10000+10];
const int INF = 10000000;

int main()
{

    int t = 0;
    int n = 0;
    int E = 0;
    int F = 0;
    int totalWeight = 0;
    int i = 0;
    int j = 0;
    cin>>t;
    while (t--)
    {
        cin>>E>>F;
        totalWeight = F - E;
        cin>>n;
        for (i=0; i<n; i++)
            cin>>coin[i].price>>coin[i].weight;
        for(i=0; i<=totalWeight; i++)
            f[i] = INF;
        f[0] = 0;
        for (i=0; i<n; i++)
            for (j=coin[i].weight; j<=totalWeight; j++)
                if (f[j] > (f[j-coin[i].weight] + coin[i].price ) )
                    f[j] = f[j-coin[i].weight] + coin[i].price;
        if (f[totalWeight] == INF)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<f[totalWeight]<<"."<<endl;
    }
    return 0;
}
