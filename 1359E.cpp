#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// an array only fulfills the condition when all vals[i] is divisible by min(vals)
// then x % v1 % a*v1 % b*v1 ... = x % v1
const int MOD = 998244353, MAXN = 1e6;
ll fac[MAXN], inv[MAXN];

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res = res*x%MOD;
        e >>= 1;
        x = x*x%MOD;
    }
    return res;
}

ll choose(int n, int r) {
    if(r>n) return 0;
    return fac[n] * inv[n-r] % MOD * inv[r] % MOD;
}

int main(){
    fastio
    int n, k;
    cin >> n >> k;

    fac[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1] * i % MOD;
    inv[n] = powe(fac[n], MOD-2);
    for(int i=n-1;i>=0;i--) inv[i] = inv[i+1] *(i+1) % MOD;

    ll res = 0;
    for(int v=1;v<=n;v++) {
        int divisors = n/v;
        // choose k-1 out of d-1 (distinct, order not matter since vals must be increasing)
        res = (res + choose(divisors-1, k-1)) % MOD;
    }
    cout << res;
}
