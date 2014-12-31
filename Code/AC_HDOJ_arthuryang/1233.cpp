////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-01 15:35:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:520KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct l
{
    int begin;
    int end;
    long long int len;
};

int compare(const void *a,const void *b)
{
    return ((struct l *)a)->len-((struct l *)b)->len;
}

int main()
{
    struct l a[10005];
    int lian[10005];
    long long int i,j,num,leng,numm;
    long long int h;
    while(scanf("%lld",&num),num!=0)
    {
        if(num==1)
        {
            printf("0\n");
            continue;
        }
        numm=2;
        for (i=1;i<=num;i++)
        {
            lian[i]=0;
        }
        h = num*(num-1)/2;
        for (i=0;i<h;i++)
        {
            scanf("%d %d %lld",&a[i].begin,&a[i].end,&a[i].len);
        }
        qsort(a,h,sizeof(struct l),compare);
        leng=a[0].len;
        lian[a[0].begin]=lian[a[0].end]=1;
        for(j=1;j<h;)
        {
            for (i=1;i<h;i++)
            {
                if((lian[a[i].begin]==0)+(lian[a[i].end]==0)==1)
                {
                    leng+=a[i].len;
                    numm++;
                    lian[a[i].begin]=lian[a[i].end]=1;
                    if(numm==num)
                    {
                        j=h;
                    }
                    break;
                }

            }
        }
        printf("%lld\n",leng);
    }
    return 0;
}
