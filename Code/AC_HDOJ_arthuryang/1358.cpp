////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-26 12:37:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1358
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:5284KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
char   a[1111111];
int next[1111111];
int main()
{
    int n;
    int len;
    int j,k;
    int num=1;
    while(scanf("%d",&n),n)
    {
        j=0;
        k=-1;
        next[j]=k;
        getchar();
        gets(a);
        cout<<"Test case #"<<num++<<endl;
        len=strlen(a);
        while(j<len)
        {
            if(k==-1 || a[k]==a[j])
            {
                j++;
                k++;
                next[j]=k;
                if(k && j%(j-k)==0)
                {
                    printf("%d %d\n",j,j/(j-k));
                }

            }
            else
                k=next[k];
        }
        cout<<endl;
    }
    return 0;
}