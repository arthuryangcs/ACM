////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-18 12:05:23
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int run(int a)
{
    if(a%400==0||(a%4==0&&a%100!=0))
        return 1;
    else
        return 0;
}

int main()
{
    char birthday[10];
    int a,year,month,day,sum,i;
    scanf("%d",&a);
    getchar();
    while(a--)
    {
        sum=0;
        gets(birthday);
        year=1000*(birthday[0]-48)+100*(birthday[1]-48)+10*(birthday[2]-48)+birthday[3]-48;
        month=10*(birthday[5]-48)+birthday[6]-48;
        day=10*(birthday[8]-48)+birthday[9]-48;
        if(month==2&&day==29)
        {
            printf("-1\n");
            continue;
        }
        else if(month>2)
            year++;
        for (i=year;i<year+18;i++)
        {
            if(run(i))
                sum+=366;
            else
                sum+=365;
        }
        printf("%d\n",sum);
    }
    return 0;
}
