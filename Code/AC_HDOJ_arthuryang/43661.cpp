////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-07-30 11:51:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4366
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:6540KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long Long;
const int MAGIC = 250;

struct staff {
    int loyalty;
    int ability;
};

bool operator < (staff a,staff b) {
    return a.ability < b.ability;
}

vector<int> adj[55555];
staff arr[55555];
int pos[55555];
map<int,int> rev;
int tot;
staff list[55555];
staff sorted[55555];
int maxl[55555];
int size[55555];
int n,q;

int dfs(int now) {
    pos[now] = tot;
    list[tot] = sorted[tot] = arr[now];
    tot ++;
    int ret = 1;
    for (int i = 0; i < adj[now].size(); i++) {
        ret += dfs(adj[now][i]);
    }
    return size[pos[now]] = ret;
}

int work(int l,int r,int val) {// 在块l,r内返回能力值 > val 的最大忠诚<br>// 二分区间端点判定
    if (sorted[r].ability <= val) return -1;
    if (sorted[l].ability > val) return maxl[l];
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (sorted[mid].ability > val) r = mid; else l = mid;
    }
    return maxl[r];
}

int main() {
    int nn;
    scanf("%d",&nn);
    while (nn--) {
        scanf("%d%d",&n,&q);
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            arr[i].loyalty = arr[i].ability = -1;
            sorted[i] = list[i] = arr[i];
        }
        memset(maxl,0,sizeof(maxl));
        memset(size,0,sizeof(size));
        memset(pos,0,sizeof(pos));
        rev.clear();
        rev[-1] = -1;// 以上是初始化
        for (int i = 1; i < n; i++) {
            int fa,l,a;
            scanf("%d%d%d",&fa,&l,&a);
            adj[fa].push_back(i);// 由于保证忠诚度不同，为了操作方便，map忠诚度到人
            rev[arr[i].loyalty = l] = i;
            arr[i].ability = a;
        }
        tot = 0;
        dfs(0);// 以上是构图DFS
        for (int i = 0; i < n; i += MAGIC) {
            int j = i + MAGIC;
            if (j > n) break;// 块内排序
            sort(sorted + i, sorted + j);// DP构造忠诚度
            maxl[j - 1] = sorted[j - 1].loyalty;
            for (int k = j - 2; k >= i; k--) {
                maxl[k] = maxl[k + 1] > sorted[k].loyalty ? maxl[k + 1] : sorted[k].loyalty;
            }
        }
        while (q--) {
            int st; scanf("%d",&st);
            int val = arr[st].ability;
            st = pos[st];
            int ed = st + size[st] - 1;
            int ans = -1;
            for (int i = st; i <= ed;) {// 二分块
                if (i % MAGIC == 0 && i + MAGIC - 1 <= ed) {
                    int tmp = work(i, i + MAGIC - 1, val);
                    if (tmp > ans) ans = tmp;
                    i += MAGIC;
                } else {// 暴力搞
                    if (list[i].ability > val && list[i].loyalty > ans) ans = list[i].loyalty;
                    i ++;
                }
            }
            printf("%d\n",rev[ans]);
        }
    }
    return 0;
}
