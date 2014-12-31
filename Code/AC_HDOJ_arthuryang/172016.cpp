////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 15:27:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1720
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:392KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long int ll;
string a,b;
int f(char s)
{
    if(s>='0' && s<='9')
        return s-'0';
    else if(s>='A' && s<='F')
        return s-'A' + 10;
    else if(s>='a' && s<='f')
        return s-'a' + 10;
}

int ff(string s)
{
    int t=0;
    for (int i=0;i<s.length() ;i++ )
    {
        t = 16*t + f(s[i]);
    }
    return t;
}

int main()
{
    while(cin>>a>>b)
        cout<<ff(a)+ff(b)<<endl;
    return 0;
}
