////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-03-12 19:58:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1084
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:416KB
//////////////////System Comment End//////////////////
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;
typedef struct stu{
	int pNum;
	string time;
	int score;
	int order;
}stu;
stu s[105];
bool Check(stu a, stu b){
	if(a.pNum < b.pNum) return true;
	if(a.pNum == b.pNum && a.time<b.time) return true;
	return false;
}
bool CheckBack(stu a, stu b){
	if(a.order < b.order) return true;
	return false;
}
int main(){
	int n, pro[6];
	while(cin>>n){
		memset(pro, 0, sizeof(pro));
		if(n<0) break;
		for(int i=0; i<n; i++){
			cin>>s[i].pNum>>s[i].time;
			s[i].order = i;
			s[i].score = 50+s[i].pNum*10;
			pro[s[i].pNum]++;
		}
		//cout<<pro[4]<<endl;
		sort(s, s+n, Check);
		int pos=0;
		int tmp=0;
		for(int i=0; i<4; i++){
			pos+=pro[i];
			if(pro[i+1]==1) tmp=pro[i+1]+1;//解决只有一个时的问题
			else tmp = pro[i+1];
			for(int j=pos; j<pos+tmp/2; j++){
				s[j].score+=5;
			}
		}
		sort(s, s+n, CheckBack);
		for(int i=0; i<n; i++){
			cout<<s[i].score<<endl;
		}
		cout<<endl;
	}
}