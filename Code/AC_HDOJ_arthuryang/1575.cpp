////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-10-14 21:15:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1575
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int m[11][11];
}Matrix;
Matrix init, unit;
int n, K;
void Init( )
{
    scanf( "%d%d", &n, &K );
    for( int i=0; i<n; ++ i )
        for( int j=0; j<n; ++ j )
        {
            scanf( "%d", &init.m[i][j] );
            unit.m[i][j]=( i == j );
        }
}
Matrix Mul( Matrix a, Matrix b )
{
    Matrix c;
    for( int i=0; i<n; ++ i )
    {
        for( int j=0; j<n; ++ j )
        {
            c.m[i][j]=0;
            for( int k=0; k<n; ++ k )
                c.m[i][j] += a.m[i][k]*b.m[k][j];
            c.m[i][j] %= 9973;
        }
    }
    return c;
}

Matrix Pow( Matrix a, Matrix b, int k )
{
    while( k>1 )
    {
        if( k&1 )
        {
            k --;
            b=Mul( a, b );
        }
        else
        {
            k >>= 1;
            a=Mul( a, a );
        }
    }
    a=Mul( a, b );
    return a;
}

int main( )
{
    int T;
    scanf( "%d", &T );
    while( T -- )
    {
        Matrix x;
        Init( );
        x=Pow( init, unit, K );
        int sum=0, i=0;
        n--;
        while( n >= 0 )
        {
            sum += x.m[n][n];
            sum%=9973;
            n --;
        }
        printf( "%d\n", sum%9973 );
    }
}
