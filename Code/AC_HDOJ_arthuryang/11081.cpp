////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-11-05 12:29:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
using  namespace std;
int main()
{
    int a,b,i,n;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin>>a>>b)
    {

        n=a>b?b:a;
        for (i=n; i>0 &&(a%i!=0 || b%i!=0);i--);
        n=a*b/i;
        cout<<n<<endl;
    }
    return 0;
}
