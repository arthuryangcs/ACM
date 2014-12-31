////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 18:18:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:372KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long int ll;
int s[1111];
int main()
{
    int x,y;
    for (int i=100;i<1000 ;i++ )
    {
        int a,b,c;
        a = i/100;
        b = i%10;
        c = i%100/10;
        if(a*a*a+b*b*b+c*c*c == i)
            s[i] = 1;
        else
            s[i] = 0;
    }
    int f;
    while(~scanf("%d%d",&x,&y))
    {
        f=1;
        for (int i=x;i<=y ;i++ )
        {
            if(s[i])
            {
                if(f)
                {
                    f = 0;
                    cout<<i;
                }
                else
                    cout<<" "<<i;
            }
        }
        if(f)
            cout<<"no";
        cout<<endl;
    }
    return 0;
}
