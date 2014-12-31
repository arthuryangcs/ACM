////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-10-14 21:23:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2000
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char a[5];
    while(scanf("%s",a)!=EOF)
    {
        sort(a,a+3);
        printf("%c %c %c\n",a[0],a[1],a[2]);
    }
}
