////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-16 21:05:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    char a[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",b[27]="VWXYZABCDEFGHIJKLMNOPQRSTU";
    char c[20];
    int i,j;
    while(1)
    {
        gets(c);
        if(strcmp(c,"ENDOFINPUT")==0)
            break;
        while(gets(str))
        {
            if(strcmp(str,"END")==0)
                break;
            for(i=0;;i++)
            {
                if(str[i]==0)
                {
                    printf("\n");
                    break;
                }
                else if(str[i]>='A'&&str[i]<='Z')
                {
                    for(j=0;j<26;j++)
                        if(str[i]==a[j])
                        {
                            printf("%c",b[j]);
                            break;
                        }
                }
                else
                    printf("%c",str[i]);
            }
        }
    }
    return 0;
}
