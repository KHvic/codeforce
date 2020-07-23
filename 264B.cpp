#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, v;
    unordered_map<ll, ll> dp;
    cin >> n;
    ll res = 1;
    for(int i=0;i<n;i++) {
        cin >> v;
        ll x = v;
        unordered_set<ll> divisors;
        for(ll j=1;j*j<=v;j++) {
            if(x%j == 0) {
                divisors.insert(j);
                divisors.insert(x/j);
            }
        }
        divisors.erase(1);
        ll mx = 1;
        for(ll divisor : divisors) mx = max(mx, dp[divisor]+1);
        for(ll divisor : divisors) dp[divisor] = mx;
        res = max(res, mx);
    }
    cout << res;
}
