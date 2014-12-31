////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-08-05 17:14:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1263
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
int main()
{
	typedef map<string, map<string, int> > Node;
	int n, m, num;
	string name, addr;
	cin >> n;
	while (n--)
	{
		Node node;
		Node::iterator pos;
		cin >> m;
		while (m--)
		{
			cin >> name >> addr >> num;
			(node[addr])[name] += num;
		}
		for (pos = node.begin(); pos != node.end(); ++pos)
		{
			cout << pos->first << endl;		// guangdong
			for (map<string, int>::iterator mpos = (pos->second).begin();
				mpos != (pos->second).end();
				++mpos
			)
			{
				cout << "   |----" << mpos->first << "("
					 << mpos->second << ")" << endl;
			}
		}
		if (n > 0)
			cout << endl;
	}
	return 0;
}
