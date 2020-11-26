#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll MOD = 998244353;

int n, m;
vector<ll> fac, inv;
ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res = res*x%MOD;
        e >>= 1;
        x = x*x%MOD;
    }
    return res;
}

void init() {
    fac = inv = vector<ll>(m+1);
    fac[0] = 1;
    for(int i=1;i<=m;i++) fac[i] = fac[i-1] * i % MOD;
    inv[m] = powe(fac[m], MOD-2);
    for(int i=m-1;i>=0;i--) inv[i] = inv[i+1] * (i+1) % MOD;
}

ll choose(int n, int r) {
    if(r>n || r<0) return 0;
    return fac[n] * inv[r] % MOD * inv[n-r] % MOD;
}

int main(){
    fastio
    cin >> n >> m;
    init();
    // choose n-1 numbers from m
    // from the n-1 numbers, n-2 possible duplicate (exclude max)
    // for the remaining n-3 numbers, 2 possible option before or after max
    ll res = n > 2 ? choose(m, n-1) * (n-2) % MOD * powe(2, n-3) % MOD : 0;
    cout << res;
}
