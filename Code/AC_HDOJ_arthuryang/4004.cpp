////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-04-14 16:41:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4004
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:460KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500500];
int l,n,m;
bool can(int mid)
{
    int i=1,j=0,step=0;

    while(i<=n+1)
    {
    if(a[i]-a[j]>mid) return false;
        step++;
        while(a[i]-a[j]<=mid&&i<=n+1) i++;
        j=i-1;

    }
    if(step>m) return false;
    else return true;

}
int main()
{
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=0;
        a[n+1]=l;
        sort(a,a+n+2);
        int ans;
        int right=l,left=0,mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(can(mid))
            {
                right=mid-1;
                ans=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
}
