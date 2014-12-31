////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-17 16:25:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3687
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN=60*60;
const int INF=200*MAXN;
int n,m;
struct point
{
	int x,y;
}Point[MAXN];

bool cmp(point a,point b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}

void Solve()
{
	int i,j,t,dis=INF,tmp;
	Point[0].x=-1;
	for(i=1;i<=m;i++)
	{
		tmp=0;
		for(j=1;j<=n*n;j++)
		{
			if(Point[j].x!=Point[j-1].x)
			{
				t=i;
			}
			tmp+=abs(Point[j].y-t);
			t++;
		}
		if(dis>tmp)dis=tmp;
	}
	printf("%d\n",dis);
}

int main()
{
	int i;
	while(~scanf("%d%d",&n,&m))
	{
		if(0==n&&0==m)break;
		for(i=1;i<=n*n;i++)
			scanf("%d%d",&Point[i].x,&Point[i].y);

		sort(Point+1,Point+1+n*n,cmp);
		Solve();
	}
	return 0;
}