////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-25 23:36:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5032
////Problem Title: 
////Run result: Accept
////Run time:3562MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define N 1010

int T, t, a, b, m, dx, dy, x;
LL ans;
int f[N];

inline void scand(int &ret) {
	char c;
	ret = 0;
	while ((c = getchar()) < '0' || c > '9')
		;
	while (c >= '0' && c <= '9')
		ret = (ret << 3) + (ret << 1) + (c - '0'), c = getchar();
}

int main() {
	int i, Y;
	scand(T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n", t);
		scand(a);
		scand(b);
		scand(m);
		for (i = 1; i <= 1000; i++)
			f[i] = (i + 1) * i / 2 + i * b;
		while (m--) {
			scand(dx);
			scand(dy);
			scand(x);
			ans = 0;
			for (i = 1; i <= x; i++) {
				Y = i * dy / dx;
				ans += (LL) f[Y] * (a + i);
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
