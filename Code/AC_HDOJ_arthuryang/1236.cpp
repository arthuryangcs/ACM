////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-31 04:44:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct en
{
    char math[23];
    int score;
};
struct en an[1001],bn;
int fen[11];
int n,g,m;
int main()
{
    int i,j,k;
    while(scanf("%d",&n),n!=0)
    {
        scanf("%d %d",&m,&g);
        for (i=0;i<m;i++)
        {
            scanf("%d",&fen[i]);
        }
        for (i=0;i<n;i++)
        {
            scanf("%s %d",an[i].math,&j);
            an[i].score=0;
            while(j--)
            {
                scanf("%d",&k);
                an[i].score+=fen[k-1];
            }
            if(an[i].score<g)
                i--,n--;
            getchar();
        }
        printf("%d\n",n);
        for (i=1;i<n;i++)
        {
            for (j=0;j<i;j++)
            {
                if(an[i].score>an[j].score  ||   ( an[i].score==an[j].score && strcmp(an[i].math,an[j].math)<0 ))
                    bn=an[i],an[i]=an[j],an[j]=bn;
            }
        }for (i=0;i<n;i++)
            printf("%s %d\n",an[i].math,an[i].score);
    }
    return 0;
}
