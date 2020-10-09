#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<int, int> pi;

ll mod = 1e9+7;
const int MAXN = 2e5+5;

ll fac[MAXN], inv[MAXN];

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
    fac[0] = 1;
    for(int i=1;i<MAXN;i++) fac[i] = fac[i-1] * i % mod;
    inv[MAXN-1] = powe(fac[MAXN-1], mod-2);
    for(int i=MAXN-2;i>=0;i--) inv[i] = inv[i+1] * (i+1) % mod;
}

ll choose(ll a, ll b) {
    return fac[a] * inv[b] % mod * inv[a-b] % mod;
}

int main()
{
    fastio
    init();
    ll h, w, a, b, x, y;
    int n;
    cin >> h >> w >> n;
    vector<pi> black;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        black.emplace_back(a, b);
    }
    black.emplace_back(h, w);
    sort(black.begin(), black.end());
    vector<ll> dp(n+1); // ways of reaching point i without touching any black
    for(int i=0;i<=n;i++) {
        tie(a, b) = black[i];
        dp[i] = choose(a+b-2, a-1);
        for(int j=0;j<i;j++) {
            tie(x, y) = black[j];
            if(y>b) continue;
            ll dx = a-x, dy = b-y;
            ll ways = choose(dx+dy, dx);
            dp[i] = (dp[i] - ways*dp[j]%mod)%mod;
        }
    }
    dp[n] = (dp[n]+mod)%mod;
    cout << dp[n];
}
