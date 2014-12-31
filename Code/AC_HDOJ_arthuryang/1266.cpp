////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 22:08:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1266
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>

int main()
{
         char str[101],*p;
         int i,x;
         scanf("%d%*c",&i);
         while(i--)
            {
                   x=0;
                   memset(str,'\0',101);
                   gets(str);
                   p=str;
                   if(str[0]=='-')
                    {
                            printf("-");
                            p++;
                   }
                   strrev(p);
                   while(*p==48){
                            p++;
                            x++;
                   }
                   printf("%s",p);
                   while(x--)
                            printf("0");
                   printf("\n");
         }
         return 0;
}
