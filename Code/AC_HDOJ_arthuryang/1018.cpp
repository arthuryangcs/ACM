////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-07-05 18:44:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#define PI 3.1415926
using namespace std;
int main()
{
	long k;
	int n;
	double len;
	cin >> n;
	while(n--)
	{
		cin >> k;
		if(k != 1)
			len = (0.5*log(2.0*PI*k) + k*log((double)k) - k) / log((double)10) + 1;
		else
			len = 1;
		cout << (long)len << endl;
	}
	return 0;
}
