////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-09-16 17:29:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4300
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:2040KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN=200000;

int next[MAXN];
int extend[MAXN];
void EKMP(char s[],char t[])//s[]为主串，t[]为模式串
{
    int i,j,p,l;
    int len=strlen(t);
    int len1=strlen(s);
    memset(next,0,sizeof(next));
    memset(extend,0,sizeof(extend));

    next[0]=len;
    j=0;
    while(j+1<len&&t[j]==t[1+j])j++;
    next[1]=j;

    int a=1;
    for(int i=2;i<len;i++)
    {
        p=next[a]+a-1;
        l=next[i-a];
        if(i+l<p+1)next[i]=l;
        else
        {
            j=max(0,p-i+1);
            while(i+j<len&&t[i+j]==t[0+j])j++;
            next[i]=j;
            a=i;
        }
    }


    j=0;
    while(j<len1&&j<len&&s[j]==t[j])j++;

    extend[0]=j;
    a=0;
    for(i=1;i<len1;i++)
    {
        p=extend[a]+a-1;
        l=next[i-a];
        if(l+i<p+1)next[i]=l;
        else
        {
            j=max(0,p-i+1);
            while(i+j<len1&&j<len&&s[i+j]==t[j])j++;
            extend[i]=j;
            a=i;
        }
    }
}

char s[MAXN],tab[MAXN],c[MAXN];
map<char,char>map1;

int main()
{
   // freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",&tab,&s);
        int len=strlen(tab);
        int len1=strlen(s);
        for(int i=0;i<len;i++)
            map1[tab[i]]='a'+i;
        for(int i=0;i<len1;i++)
           c[i]=map1[s[i]];
        c[len1]=0;
        EKMP(s,c);

        int k;
        for(k=(len1+1)/2;k<len1;k++)
        {
            if(k+extend[k]==len1)
              break;
        }
        for(int i=0;i<k;i++)printf("%c",s[i]);
        for(int i=0;i<k;i++)printf("%c",map1[s[i]]);
        printf("\n");
    }
    return 0;
}