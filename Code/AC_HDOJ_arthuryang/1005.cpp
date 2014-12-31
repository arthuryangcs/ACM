////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2012-12-28 12:22:06
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{     
	int a,b,n;     
	while(scanf("%d %d %d",&a,&b,&n)!=EOF&&(a+b+n)!=0) 
	{   
		int f1=1,f2=1,f3=1,t,r[8][8]={0},i,flag=0,x;          
		for(i=3;i<=n;i++)  
		{      
			f3=(a*f2+b*f1)%7;               
			r[f1][f2]=i;               
			f1=f2;                
			f2=f3;                
			if(r[f1][f2]&&flag==0)   
			{                   
				t=i-r[f1][f2]+1;         
				i=r[f1][f2]-3;       
				n=(n-i)%t+i;       
					if(n==i)         
						n=t+i;            
					if(n==(i+1)) 
					{
						f3=f1;
						break;
					}         
					if(n==(i+2)) 
					{
						f3=f2;
						break;
					}                      
					i+=2;       
					flag=1;      
              }        
        }       
		printf("%d\n",f3);   
    }    
	return 0;
}
