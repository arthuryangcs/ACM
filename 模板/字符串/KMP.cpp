#include <cstring>
int next[110];
//kmp模板
//注意这里next在打出时是从1开始的，但是字符串中存的是从0开始
void get_next(char t[])//获得next数组，相当于自己和自己匹配
{
	int i,j;
	i=1;
	next[1]=0;//利用递归打的表，要初始化
	j=0;//这里j必须是比i小的
	while(i<strlen(t))
	{
		if(j==0||t[i-1]==t[j-1])//这里next中的下标要减一再用在字符串中
		{
			i++;
			j++;
			if(t[i-1]!=t[j-1])
				next[i]=j;
			else
				next[i]=next[j];//这里是一种优化

		}
		else
			j=next[j];//向前找
	}
}

int kmp(char s[],char t[])
{
	get_next(t);
	int i,j;
	int lens,lent;
	i=1;//从1开始
	j=1;
	while(i<=strlen(s)&&j<=strlen(t))
	{
		if(j==0||s[i-1]==t[j-1]){i++;j++;}
		else
			j=next[j];
	}
	if(j>strlen(t))
		return 1;//这里也可以返回i-strlen（t）来获得匹配在主串中开始的位置
	else
		return 0;
}
