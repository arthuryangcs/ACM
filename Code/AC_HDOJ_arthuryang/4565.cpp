////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2013-11-19 19:44:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4565
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:368KB
//////////////////System Comment End//////////////////
    #include <iostream>  
    #include <stdio.h>  
      
    using namespace std;  
      
    #define N 2  
    #define ll long long  
      
    struct Matrix {  
        ll v[N][N];  
    };  
      
    Matrix A,B={1L,0L,0L,1L};  
    ll M;  
      
    Matrix mul(Matrix m1,Matrix m2,ll M){  
        int i,j,k;  
        Matrix c;  
        for(i = 0; i < N; i++)  
            for(j = 0; j < N; j++){  
                c.v[i][j] = 0;  
                for(k = 0; k < N; k++){  
                    c.v[i][j] += (m1.v[i][k]*m2.v[k][j])%M;  
                    c.v[i][j] %= M;  
                }  
                c.v[i][j] %= M;  
        }  
        return c;  
    }  
      
    Matrix Mpow(Matrix A,Matrix B,ll n,ll M){  
        Matrix x = A,c = B;  
        while(n >= 1){  
            if(n&1L)c = mul(c,x,M);  
            n >>= 1;  
            x = mul(x,x,M);  
        }  
        return c;  
    }  
      
    int main() {  
        //freopen("F:\\problem A\\in.txt","r",stdin);  
        //freopen("F:\\problem A\\out.txt","w",stdout);  
        ll n, a, b, t;  
        while(cin>>a>>b>>n>>M){  
            if(n == 1){  
                cout << (2*(a%M)) % M <<endl;continue;  
            }  
            if(n == 2){  
                cout << ((2*((a%M)*(a%M))%M)%M + (2*b)%M) % M <<endl;continue;  
            }  
            A.v[0][0] = (2*(a%M)) % M;  
            t = a;  
            t *= a;  
            A.v[0][1] = 1;  
            t = b - t;  
            while(t < 0)t += M;  
            A.v[1][0] = t;  
            A.v[1][1] = 0;  
            Matrix p = Mpow(A,B,n-2,M), q = {((2*((a%M)*(a%M))%M)%M + (2*b)%M) % M, (2*(a%M)) % M, 0L, 0L};  
            p = mul(q,p,M);  
            cout<<p.v[0][0]<<endl;  
        }  
        return 0;  
    }  