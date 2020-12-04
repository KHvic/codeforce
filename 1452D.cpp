#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 998244353;

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res = res*x%mod;
        e >>= 1;
        x = x*x%mod;
    }
    return res;
}

// observation: answer is number of ways to split n into amount of odd numbers
// fibonacci can be used to represent such problems

int main(){
    fastio
    int n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[0] = dp[2] = dp[1] = 1;
    for(int i=2;i<=n;i++) dp[i] = (dp[i-1]+dp[i-2])%mod;
    ll res = dp[n] * powe(powe(2, n), mod-2) % mod;
    cout << res;
}
