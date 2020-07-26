#include <bits/stdc++.h>
using namespace std;
#define ll long

ll r, g, t, h;
int mod = 1e9+7;

// topdown, MLE
//vector<vector<ll>> dp;
//ll solve(int idx, int redleft) {
//    if(idx>=h) return 1;
//    else if(dp[idx][redleft] != -1) return dp[idx][redleft];
//    // compute green left
//    ll totalused = idx*(idx+1)/2;
//    ll redused = r - redleft;
//    ll greenused = totalused - redused;
//    ll greenleft = g - greenused;
//    ll res = 0;
//    if(greenleft >= (idx+1)) {
//        res += solve(idx+1, redleft);
//        res %= mod;
//    }
//    if(redleft >= (idx+1)) {
//        res += solve(idx+1, redleft - (idx+1));
//        res %= mod;
//    }
//    return dp[idx][redleft] = res;
//}

ll solve2() {
    vector<ll> dp[2];
    dp[0].assign(r+1,0);
    dp[1].assign(r+1,0);
    dp[0][0] = 1;
    for(int idx=1;idx<=h;idx++) {
        fill(dp[idx%2].begin(), dp[idx%2].end(), 0);
        for(int redused=0;redused<=r;redused++) {
            // compute green left
            ll totalused = idx*(idx-1)/2;
            ll greenused = totalused - redused;
            ll greenleft = g - greenused;
            if(greenleft >= idx) {
                dp[idx%2][redused] += dp[1-idx%2][redused];
                dp[idx%2][redused] %= mod;
            }
            if(redused+idx <= r) {
                dp[idx%2][redused+idx] += dp[1-idx%2][redused];
                dp[idx%2][redused+idx] %= mod;
            }
        }
    }
    ll res = 0;
    for(ll x : dp[h%2]) {
        res = (res+x) % mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> r >> g;
    // n*(n+1)/2 blocks to form n layers
    // n*(n+1) = 2*(r + g)
    // find highest h <= 2*(r+g)
    t = r+g;
    h = sqrt(2*t);
    while(h*(h+1) > 2*t) h--;
    cout << solve2();
}
