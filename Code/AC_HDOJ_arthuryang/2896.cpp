////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-07 15:47:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2896
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:29964KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    node *next[130],*fail;
    int id;
    node()
    {
        memset(next,0,sizeof(next));
        fail=NULL;
        id=0;
    }
}*head;
char s[10005],t[205];
set<int,less<int> > out;
void build(char *x,node *head,int id)
{
    int len=strlen(x);
    for(int i=0; i<len; ++i)
    {
        int k=x[i];
        if(head->next[k]==NULL)
            head->next[k]=new node();
        head=head->next[k];
    }
    head->id=id;
}
void build_fail(node *head)
{
    node *now,*p;
    queue<node*> q;
    head->fail=NULL;
    q.push(head);
    for(; !q.empty();)
    {
        now=q.front();
        q.pop();
        for(int i=0; i<130; ++i)
            if(now->next[i])
            {
                p=now->fail;
                for(; p&&!p->next[i];) p=p->fail;
                now->next[i]->fail=p?p->next[i]:head;
                q.push(now->next[i]);
            }
    }
}
void ac_find(node *head,char *s)
{
    int len=strlen(s);
    out.clear();
    node *p=head;
    for(int i=0;i<len;++i)
    {
        int k=s[i];
        for(;p->next[k]==NULL&&p!=head;p=p->fail);
        p=p->next[k]==NULL?head:p->next[k];
        node *tmp=p;
        for(;tmp!=head;)
        {
            if(tmp->id)
               out.insert(tmp->id);
            tmp=tmp->fail;
        }
    }
}
int main()
{
    int n,m;
    for(; ~scanf("%d",&n);)
    {
        head=new node();
        for(int i=1; i<=n; ++i)
        {
            scanf("%s",t);
            build(t,head,i);
        }
        build_fail(head);
        int summ=0;
        scanf("%d",&m);
        for(int i=1; i<=m; ++i)
        {
            scanf("%s",s);
            ac_find(head,s);
            if(out.size()!=0)
            {
                printf("web %d:",i);
                for(set<int>::iterator it=out.begin();it!=out.end();++it)
                    printf(" %d",*it);
                printf("\n");
                summ++;
            }
        }
        printf("total: %d\n",summ);
    }
    return 0;
}
