////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-06-18 21:17:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3265
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:7456KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

const int MAXN = 50010;

struct Line {
    int y, x_st, x_ed, flag;
    Line() {}
    Line(int y, int x_st, int x_ed, int flag):
        y(y), x_st(x_st), x_ed(x_ed), flag(flag) {}
    bool operator < (const Line &rhs) const {
        return y > rhs.y;
    }
};

Line a[MAXN * 8];
int tree[MAXN * 4], sum[MAXN * 4];
LL ans;

void update(int x, int l, int r, int tl, int tr, int t) {
    int lc = x << 1, rc = lc ^ 1;
    if(tl <= l && r <= tr) {
        tree[x] += t;
        if(tree[x] > 0) sum[x] = r - l;
        else if(r - l == 1) sum[x] = 0;
        else sum[x] = sum[lc] + sum[rc];
    }
    else {
        int mid = (l + r) >> 1;
        if(tl < mid) update(lc, l, mid, tl, tr, t);
        if(tr > mid) update(rc, mid, r, tl, tr, t);
        if(tree[x] == 0) sum[x] = sum[lc] + sum[rc];
        else sum[x] = r - l;
    }
}

void solve(int n) {
    sort(a, a + n);
    ans = 0;
    for(int i = 0; i < n; ++i) {
        if(i > 0) ans += (a[i - 1].y - a[i].y) * LL(sum[1]);
        update(1, 0, 50000, a[i].x_st, a[i].x_ed, a[i].flag);
    }
}

int main() {
    int n, x[5], y[5];
    while(scanf("%d", &n) != EOF) {
        if(n == 0) break;
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= 4; ++j) scanf("%d%d", &x[j], &y[j]);
            if(x[1] != x[3]) {
                a[cnt++] = Line(y[2], x[1], x[3], 1);
                a[cnt++] = Line(y[1], x[1], x[3], -1);
            }
            if(x[2] != x[4]) {
                a[cnt++] = Line(y[2], x[4], x[2], 1);
                a[cnt++] = Line(y[1], x[4], x[2], -1);
            }
            if(y[1] != y[3]) {
                a[cnt++] = Line(y[3], x[3], x[4], 1);
                a[cnt++] = Line(y[1], x[3], x[4], -1);
            }
            if(y[2] != y[4]) {
                a[cnt++] = Line(y[2], x[3], x[4], 1);
                a[cnt++] = Line(y[4], x[3], x[4], -1);
            }
        }
        solve(cnt);
        cout<<ans<<endl;
    }
}