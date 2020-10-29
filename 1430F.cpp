#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef tuple<ll, ll, ll> ii;

int main(){
    fastio
    int n;
    ll k, l, r, a;
    cin >> n >> k;
    vector<ii> waves;
    for(int i=0;i<n;i++) {
        cin >> l >> r >> a;
        waves.emplace_back(l, r, a);
    }
    vector<ll> dp(n, 1e16); // min bullet use with full mag at round i
    dp[0] = 0;
    ll res = 1e16;
    // reload before round i
    for(int i=0;i<n;i++) {
        ll remain = k, total = dp[i];
        for(int j=i;j<n;j++) {
            tie(l, r, a) = waves[j];
            ll reloadNeeded = (max(0LL, a-remain)+(k-1))/k;
            if(reloadNeeded > r-l) break;

            total += a;
            remain = remain + reloadNeeded*k - a;

            if(j+1 == n) {
                res = min(res, total);
            } else if(l + reloadNeeded < get<0>(waves[j+1]))
                // can reload before j+1, use remain magazine
                dp[j+1] = min(dp[j+1], total + remain);
        }
    }
    cout << (res < 1e16 ? res : -1);
}
