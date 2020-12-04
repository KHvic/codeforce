#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> vals(n), dp(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    ll res = 0;
    // start new sequence of at most length m at each index
    // this sequence incur a cost of -k
    for(int i=0;i<n;i++) {
        ll sum = -k;
        for(int j=i;j>=0 && i-j+1<=m;j--) {
            sum += vals[j];
            ll prev = j==0 ? 0 : dp[j-1];
            dp[i] = max(dp[i], prev+sum);
        }
        res = max(dp[i], res);
    }
    cout << res;
}
