#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 1e9+7;

int main(){
    fastio
    ll n;
    cin >> n;
    ll hh = 19, hs = 26-hh, sh = 6, ss = 26-sh;
    vector<vector<ll>> mat = {{hh, hs}, {sh, ss}};
    auto multiplyM = [](vector<vector<ll>>& a, vector<vector<ll>>& b) {
        vector<vector<ll>> res(2, vector<ll>(2));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % mod;
        return res;
    };
    vector<vector<ll>> res = {{1,0},{0,0}}; // currently happy only
    while(n) {
        if(n&1) res = multiplyM(res, mat);
        n >>= 1;
        mat = multiplyM(mat, mat);
    }
    cout << res[0][0];
}
