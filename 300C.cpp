#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9+7;
const int MAXN = 1e6+10;
ll fact[MAXN], invfact[MAXN];

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res=res*x%mod;
        x=x*x%mod;
        e>>=1;
    }
    return res;
}

ll inv(ll x) {
    return powe(x, mod-2);
}

ll combine(ll n, ll a) {
    return fact[n]*invfact[a]%mod*invfact[n-a]%mod;
}

void init(int n) {
    fact[0] = 1;
    for(int i=1;i<=n;i++) fact[i] = fact[i-1]*i%mod;
    invfact[n] = inv(fact[n]);
    for(int i=n-1;i>=0;i--) invfact[i] = invfact[i+1]*(i+1)%mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, n;
    cin >> a >> b >> n;
    init(n);
    // find a*x + b*y = good where x+y = n
    ll res = 0;
    for(int x=0;x<=n;x++) {
        int y=n-x;
        ll val = a*x+b*y;
        bool good = true;
        while(val && good) {
            int cur = val%10;
            good &= (cur==a || cur==b);
            val/=10;
        }
        if(good) {
            // nCx ways to get this good number
            res += (combine(n,x));
            res %= mod;
        }
    }
    cout << res;
}
