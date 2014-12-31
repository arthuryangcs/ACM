////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-01 10:43:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1159
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:4288KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int a[1005][1005];
char s1[1005];
char s2[1005];
int main()
{
    int i,j;
    int len1,len2;
    for (i=0;i<1005;i++)
    {
        a[i][0] = a[0][i] = 0;
    }
    while(~scanf("%s %s",s1,s2))
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        for (i=1;i<=len1;i++)
        {
            for (j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    a[i][j] = a[i-1][j-1]+1;
                }
                else
                {
                    a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
                }
            }
        }
        printf("%d\n",a[len1][len2]);
    }
    return 0;
}
