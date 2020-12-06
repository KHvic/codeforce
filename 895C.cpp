#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long


// observation:
// a perfect square number has even numbers of prime divisors for all possible prime
// we can solve using dp[value][bitmask primes], after considering value
// transition when using odd number of some values to dp[value+1][bitmask ^ value]
// transition when using even number of some value to dp[value+1[bitmask]
// combine this with combinatorics of choosing some indexes for that value

const int N = 71, P = 19;
vector<int> primes;

void sieve() {
    bitset<N> isprime;
    isprime.set();
    for(int i=2;i<N;i++) {
        if(isprime[i]) {
            for(int j=i*i;j<N;j+=i) isprime[j] = false;
            primes.push_back(i);
        }
    }
}

// bitmask representing even or odd count of prime for some number
int toBitmask(int x) {
    if(x==0) return 0;
    int bitmask = 0;
    for(int i=0;i<primes.size();i++) {
        while((x % primes[i]) == 0) {
            x /= primes[i];
            bitmask ^= (1<<i);
        }
    }
    return bitmask;
}

ll mod = 1e9+7;
struct Binom {
    int n;
    vector<ll> fac, inv;
    Binom(int n): n(n) {
        fac = inv = vector<ll>(n+1, 1);
        for(int i=1;i<=n;i++) fac[i] = fac[i-1] * i % mod;
        inv[n] = powe(fac[n], mod-2);
        for(int i=n-1;i>=0;i--) inv[i] = inv[i+1] * (i+1) % mod;
    }

    ll choose(int n, int r) {
        if(r>n || r<0) return 0;
        return fac[n] * inv[r] % mod * inv[n-r] % mod;
    }

    ll permute(int n, int r) {
        if(r>n || r<0) return 0;
        return fac[n] * inv[n-r] % mod;
    }

    ll powe(ll x, ll e) {
        ll r = 1;
        while (e) {
            if (e & 1) r = r * x % mod;
            x = x * x % mod;
            e >>= 1;
        }
        return r;
    }
};

int dp[N+1][1<<P];

int main(){
    fastio
    sieve();
    vector<int> cnt(N);
    int n, v;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
    }
    dp[0][0] = 1;
    Binom binom(n);
    for(int i=0;i<N;i++) {
        int bits = toBitmask(i);
        ll total = cnt[i];
        ll evenWays = 0, oddWays = 0;
        for(int j=0;j<=total;j++) {
            ll ways = binom.choose(total, j);
            if(j%2) oddWays = (oddWays + ways) % mod;
            else evenWays = (evenWays + ways) % mod;
        }
        for(int j=0;j<(1<<P);j++) {
            dp[i+1][j] = (dp[i+1][j] + evenWays*dp[i][j]) % mod;
            dp[i+1][j ^ bits] = (dp[i+1][j ^ bits] + oddWays*dp[i][j]) % mod;
        }
    }
    cout << dp[N][0] - 1; // subtract for non-empty subset
}
