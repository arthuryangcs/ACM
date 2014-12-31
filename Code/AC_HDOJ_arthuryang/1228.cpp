////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-12-09 21:47:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ff(string ss)
{
    if(ss=="one")
        return 1;
    if(ss=="zero")
        return 0;
    if(ss=="two")
        return 2;
    if(ss=="three")
        return 3;
    if(ss=="four")
        return 4;
    if(ss=="five")
        return 5;
    if(ss=="six")
        return 6;
    if(ss=="seven")
        return 7;
    if(ss=="eight")
        return 8;
    if(ss=="nine")
        return 9;
}
int main()
{
    string s;
    int a,b;
    a=b=0;
    int f= 0;
    while(cin>>s)
    {
        if(s=="=")
        {
            if(a+b==0)
                return 0;
            printf("%d\n",a+b);
            a=b=f=0;
        }
        else if(s!="+")
        {
            if(f==0)
                a= a*10+ff(s);
            else
                b = b*10+ff(s);

        }
        else
            f=1;
    }
}
