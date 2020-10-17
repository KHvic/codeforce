#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// for a number n, we want to partition it into f parts with gcd = 1
// observation 1: (count wayts to partitioning to f segments)
// number of ways P to partition N into F parts, P = C(N-1, F-1)
// explanation:
// f1 + f2 + f3 ... = n, where fx >= 1
// then b1 + b2 + b3 ... = n-f where bx >= 0 & f is number of partitions
// then by bars and stars for partitioning => Choose(n-f+(f-1), f-1) = C(n-1, f-1)

// observation 2:
// by PIE, |gcd==1| = T - |gcd==prime_size1| + |gcd==prime_size2| - |gcd==prime_size3| ...
// |gcd==prime_sizex| can be computed using observation one P = C(remaining_to_distribute-1, F-1)
// remaining = N / PROD(primes)

const ll mod = 1e9+7, MAXN = 1e5+5;
ll fact[MAXN], inv[MAXN];

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res = res*x%mod;
        e >>= 1;
        x = x*x%mod;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for(int i=1;i<MAXN;i++) fact[i] = fact[i-1] * i % mod;
    inv[MAXN-1] = powe(fact[MAXN-1], mod-2);
    for(int i=MAXN-2;i>=0;i--) inv[i] = inv[i+1] * (i+1) % mod;
}

ll choose(int n, int r) {
    if(r<0 || r>n) return 0;
    return fact[n]*inv[r]%mod*inv[n-r]%mod;
}

ll solve(int n, int f) {
    vector<int> primes;
    int v = n;
    for(ll i=2;i*i<=v;i++) {
        if(v%i==0) {
            primes.push_back(i);
            while(v%i==0) v /= i;
        }
    }
    if(v>1) primes.push_back(v);

    int len = primes.size();
    ll res = 0;
    for(int i=0;i<(1<<len);i++) {
        ll remain = n;
        int bitcount = __builtin_popcount(i);
        int mul = 1;
        for(int j=0;j<len;j++)
            if(i&(1<<j)) remain /= primes[j];
        int sign = bitcount&1 ? -1 : 1;
        (res += 1LL*sign*choose(remain-1, f-1)%mod) %= mod;
    }
    return (res+mod)%mod;
}

int main(){
    fastio
    init();
    int q, n, f;
    cin >> q;
    while(q--) {
        cin >> n >> f;
        cout << solve(n, f) << "\n";
    }
}
