#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

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

int main(){
    fastio
    int n, k;
    cin >> n >> k;
    map<ll, ll> events;
    ll l, r;
    for(int i=0;i<n;i++) {
        cin >> l >> r;
        events[l]++;
        events[r+1]--;
    }
    ll prev = -1e8;
    ll cur = 0, res = 0;
    Binom binom(n);
    for(auto& event : events) {
        if(cur>=k) {
            ll diff = event.first - prev;
            res += binom.choose(cur, k)*diff%mod;
            res %= mod;
        }
        prev = event.first;
        cur += event.second;
    }
    cout << res;
}
