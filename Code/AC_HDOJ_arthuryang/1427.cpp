////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-05-01 19:50:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1427
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int number[4];
bool PointsGame(int n);

int main()
{
    
    char s[2];
    int index = 0;
    while(scanf("%s", s) != EOF)
    {
        if(s[0] > '1' && s[0] <= '9')
            number[index++] = s[0] - '0';
        else if(s[0] == 'A')
            number[index++] = 1;
        else if(s[0] == 'J')
            number[index++] = 11;
        else if(s[0] == 'Q')
            number[index++] = 12;
        else if(s[0] == 'K')
            number[index++] = 13;
        else if(s[0] == '1' && s[1] == '0')
            number[index++] = 10;
        if(index == 4)
        {
            if(PointsGame(4))
                printf("Yes\n");
            else
                printf("No\n");
            getchar();
            index = 0;
        }
    }
       return 0;
}


bool PointsGame(int n)
{
    if(n == 1)
    {
        if(number[0] == 24)
            return true;
        else
            return false;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int a, b;
            a = number[i];
            b = number[j];
            number[j] = number[n - 1];

            number[i] = a + b;
            if(PointsGame(n - 1))
                return true;

            number[i] = a - b;
            if(PointsGame(n - 1))
                return true;

            number[i] = b - a;
            if(PointsGame(n - 1))
                return true;

            number[i] = a * b;
            if(PointsGame(n - 1))
                return true;
                
            if(b != 0)
            {
                int tmp = a / b;
                if(tmp * b == a)
                {
                    number[i] = tmp;
                    if(PointsGame(n - 1))
                        return true;
                }
            }
            
            if(a != 0)
            {
                int tmp = b / a;
                if(tmp * a == b)
                {
                    number[i] = tmp;
                    if(PointsGame(n - 1))
                        return true;
                }
            }
            
            number[i] = a;
            number[j] = b;
        }
    }
    return false;
}
