////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-02-07 00:02:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:28468KB
//////////////////System Comment End//////////////////
# include<stdio.h>
# include<queue>
# include<string.h>
# define MAX 26
using namespace std;
struct Trie{
    int count;
    struct Trie *next[MAX],*fail;
};
queue<Trie *>q;
char keyword[55];//记录单词
char str[1000005];//记录模式串
Trie *NewTrie()
{
    int i;
    Trie *temp=new Trie;
    temp->count=0;
    for(i=0;i<MAX;i++)
        temp->next[i]=NULL;
    return temp;
}
void Insert(Trie *p,char s[])
{
    int i;
    Trie *temp=p;
    i=0;
    while(s[i])
    {
        if(temp->next[s[i]-'a']==NULL) temp->next[s[i]-'a']=NewTrie();
        temp=temp->next[s[i]-'a'];
        i++;
    }
    temp->count++;
}
void bulid_ac_automation(Trie *root)
{
    int i;
    q.push(root);
    root->fail=NULL;
    while(!q.empty())
    {
        Trie *temp=q.front();
        q.pop();
        Trie *p=NULL;
        for(i=0;i<MAX;i++)
        {
            if(temp->next[i]!=NULL)
            {
                if(temp==root) temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }//if
                        p=p->fail;
                    }//while
                    if(p==NULL) temp->next[i]->fail=root;
                }//else
                q.push(temp->next[i]);
            }//if
        }//for
    }//while
}//void
int query(Trie *root)
{
    int i,cnt,index,len;
    i=0;
    cnt=0;
    len=strlen(str);
    Trie *p=root;
    while(str[i])
    {
        index=str[i]-'a';
        while(p->next[index]==NULL && p!=root) p=p->fail;
        p=p->next[index];
        if(p==NULL) p=root;
        Trie *temp=p;
        while(temp!=root && temp->count!=-1)
        {
            cnt+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}
int main()
{
    int i,n,ncase,cnt;
    Trie *p;
    scanf("%d",&ncase);
    while(ncase--)
    {
        p=NewTrie();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%s",keyword);
            Insert(p,keyword);
        }
        scanf("%s",str);
        bulid_ac_automation(p);
        cnt=query(p);
        printf("%d\n",cnt);
    }
    return 0;
}