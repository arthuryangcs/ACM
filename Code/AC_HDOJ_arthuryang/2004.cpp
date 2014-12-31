////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 17:34:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:368KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long int ll;
int main()
{
    int a;
    while(cin>>a)
    {
        if(a>100)
            cout<<"Score is error!"<<endl;
        else if(a>=90)
            cout<<"A"<<endl;
        else if(a>=80)
            cout<<"B"<<endl;
        else if(a>=70)
            cout<<"C"<<endl;
        else if(a>=60)
            cout<<"D"<<endl;
        else if(a>=0)
            cout<<"E"<<endl;
        else
            cout<<"Score is error!"<<endl;
    }
    return 0;
}
