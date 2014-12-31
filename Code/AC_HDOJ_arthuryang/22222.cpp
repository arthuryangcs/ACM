////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-07 00:59:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:29848KB
//////////////////System Comment End//////////////////

#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int t;
int n;
char ss[1100000];
int next[260010][26];
int c[260010];
int fail[260010];
int num;
void insert(char s[])
{
    int t = 1;
    int len = strlen(s);
    for (int i=0;i<len ;i++ )
    {
    	if(next[t][s[i]-'a']==0)
    	    next[t][s[i]-'a'] = num++;
        t = next[t][s[i]-'a'];
    }
    c[t]++;
}

void makeAC()
{
    queue<int> q;
    q.push(1);
    int t,tt;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for (int i=0;i<26 ;i++ )
        {
        	if(next[t][i])
        	{
        	    tt = fail[t];
                while(tt)
                {
                    if(next[tt][i])
                    {
                        fail[next[t][i]] = next[tt][i];
                        break;
                    }
                    tt = fail[tt];
                }
                if(tt == 0)
                    fail[next[t][i]] = 1;
                q.push(next[t][i]);
        	}
        }
    }
}

int count(char s[])
{
    int tt;
    int n = 0,t = 1;
    int len = strlen(s);
    for (int i=0;i<len ;i++ )
    {
    	if(next[t][s[i]-'a'])
            t = next[t][s[i]-'a'];
        else
        {
            while(t!=1 && next[t][s[i]-'a']==0)
                t = fail[t];
                if(t!=1 || next[t][s[i]-'a'])
                    t = next[t][s[i]-'a'];
        }
        tt = t;
        while(tt!=1 && c[tt]!=-1)
        {
            n += c[tt];
            c[tt] = -1;
            tt = fail[tt];
        }
        //cout<<n<<endl;
    }
    return n;
}

int main()
{
    //freopen("slyar.out", "r", stdin);
    scanf("%d",&t);
    char s[111];
    for (int i=0;i<t ;i++ )
    {
        num = 2;
        memset(next,0,sizeof(next));
        memset(c,0,sizeof(c));
        memset(fail,0,sizeof(fail));
    	scanf("%d",&n);
    	for (int j=0;j<n ;j++ )
    	{
    		scanf("%s",s);
    		insert(s);
    	}
    	makeAC();
    	scanf("%s",ss);
    	printf("%d\n",count(ss));
    }
    return 0;
}
