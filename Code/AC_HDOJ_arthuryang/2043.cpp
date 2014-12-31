////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-07 23:20:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    char a[51];
    int n,j,i,b,c,d,e;
    while(scanf("%d",&n)!=EOF)
    {
        for(j=0;j<n;j++)
        {
            b=0;c=0;d=0;e=0;
            scanf("%s",a);
            if(strlen(a)>16||strlen(a)<8)
            {
                printf("NO\n");
            }
            else
            {
                for(i=0;i<strlen(a);i++)
                {
                    if(a[i]>='A'&&a[i]<='Z')
                    {
                        b=1;
                    }
                    else if(a[i]>='a'&&a[i]<='z')
                    {
                        c=1;
                    }
                    else if(a[i]>='0'&&a[i]<='9')
                    {
                        d=1;
                    }
                    else if(a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^'||a[i]=='~')
                    {
                        e=1;
                    }
                }
                if((b+c+d+e)>2)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}
