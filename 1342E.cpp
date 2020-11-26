#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll MOD = 998244353;

// observation 1:
// for a column with x rooks, there are x-1 pairs
// thus, assuming that each rows have at most 1 rook, we can simplify the problem
// also, number of rooks in some amount of columns will always sum up to same pair count
// what only matters is the number of columns selected
// number of columns needed to distribute n rooks: k = n-c, c = n-k, having another column decrease count by one

// total ways of having exactly k pairs is thus => (n-k)^n
// however, some of the columns could be not selected
// using principle of inclusion exclusion, we exclude these counts
// also have to multiply result by nC(n-k), number of ways to select the columns

int n, k;
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
    fac = inv = vector<ll>(n+1);
    fac[0] = 1;
    for(int i=1;i<=n;i++) fac[i] = fac[i-1] * i % MOD;
    inv[n] = powe(fac[n], MOD-2);
    for(int i=n-1;i>=0;i--) inv[i] = inv[i+1] * (i+1) % MOD;
}

ll combination(int n, int r) {
    if(r>n || r<0) return 0;
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}

int main(){
    fastio
    cin >> n >> k;
    init();
    int c = n-k;
    ll res = 0;

    for(int i=0;i<=c;i++) {
        int sign = i%2==0 ? 1 : -1;
        ll waysExclude = combination(c, i);
        ll waysDistribute = powe(c-i, n);
        res += sign*(waysExclude*waysDistribute%MOD);
        res = ((res%MOD) + MOD) % MOD;
    }
    res = res*combination(n, c)%MOD;
    if(k) res = res*2LL%MOD; // switch orientation row - col
    cout << res;
}
