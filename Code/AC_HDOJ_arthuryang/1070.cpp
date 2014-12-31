////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-01-17 11:28:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<math.h>
char a[1001][101];
int b[1001][3];
float f[1001];
int main()
{
    int c,d,i,mi;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&d);
        mi=0;
        for(i=0;i<d;i++)
        {
            scanf("%s %d %d",a[i],&b[i][0],&b[i][1]);
            b[i][2]=b[i][1];
            if(b[i][1]>1000)
                b[i][1]=1000;
            b[i][1]-=b[i][1]%200;
            f[i]=1.0*b[i][1]/b[i][0];
            if(f[mi]<f[i] || (fabs(f[mi]-f[i])<1e-5 && b[i][2]>b[mi][2]))
                mi=i;
        }
        printf("%s\n",a[mi]);
    }
    return 0;
}
