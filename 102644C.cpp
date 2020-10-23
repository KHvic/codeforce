#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 1e9+7;

struct Matrix {
    ll m[2][2];
    Matrix operator *(Matrix other) {
        Matrix res{{{0,0},{0,0}}};
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k]*other.m[k][j]%mod)%mod;
        return res;
    }
};

int main(){
    fastio
    ll n;
    cin >> n;
    // F(n-1) = 0a+1b
    // F(n)   = 1a+1b
    // F(N,N+1) = M(01,11)^x * M(0,1)
    Matrix m{{{0, 1},{1, 1}}};
    Matrix res{{{1, 0}, {0, 1}}};
    while(n) {
        if(n&1) res = res*m;
        n >>= 1;
        m = m*m;
    }
    cout << (res.m[0][1]) % mod;
}
