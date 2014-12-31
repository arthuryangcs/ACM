////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2012-12-21 13:37:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,len1,len2,j,k,pi,t,flag;
    char str1[1010],str2[1010];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int a[1200]={0};
        flag=0;
        printf("Case %d:\n",i);
        scanf("%s%s",str1,str2);//以字符串形式读入
        len1=strlen(str1);
        len2=strlen(str2);
        printf("%s + %s = ",str1,str2);
        j=len1-1;
        k=len2-1;
        pi=0;
        while(j>=0&&k>=0)//开始相加
        {
            if(a[pi]+(str1[j]-'0')+(str2[k]-'0')>=10)//相加后大于10的
            {
                a[pi]=a[pi]+(str1[j]-'0')+(str2[k]-'0')-10;
                a[pi+1]++;
            }
            else
                a[pi]=a[pi]+(str1[j]-'0')+(str2[k]-'0');
            pi++;
            k--;
            j--;
        }
        if(j>=0)
        {
            for(t=j;t>=0;t--)
            {
                a[pi]=a[pi]+(str1[t]-'0');
                pi++;
            }
        }
        else if(k>=0)
        {
            for(t=k;t>=0;t--)
            {
                a[pi]=a[pi]+str2[t]-'0';
                pi++;
            }
        }
        else if(a[pi]!=0)//对于位数相同2个数加后最高位大于10的
            pi++;
        for(t=pi-1;t>=0;t--)
        {
            if(a[t]==0&&flag==0)//处理一次啊前导0，估计属于无用的一步
                continue;
            else
            {
                flag=1;
                printf("%d",a[t]);
            }
           
        }
        printf("\n");
        if(i!=n)//对于2组之间加空行的情况
            printf("\n");
    }
    return 0;   
}
 
