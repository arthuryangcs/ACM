////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 15:17:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:640KB
//////////////////System Comment End//////////////////
#include<stdio.h>

#include<string.h>

int f[100000];

int hash[100000];

int main()

{

    int t,m,y,cnt,n,i;

    scanf("%d",&t);

    while(t--)

    {

        scanf("%d",&n);

        if(n<0)

        {

            printf("-");

            n*=-1;

        }

        if(n==1)

        {

            printf("1\n");

            continue;

        }

        y=1;cnt=0;

        memset(hash,0,sizeof(hash));

        hash[1]=1;

        while(y)

        {

            y*=10;

            f[cnt++]=y/n;

            y%=n;

            if(hash[y])

            break;

            hash[y]=1;

        }

        printf("0.");

        for(i=0;i<cnt;i++)

        printf("%d",f[i]);

        printf("\n");

    }

    return 0;

}