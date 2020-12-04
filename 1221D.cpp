#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> vals(n), cost(n);
        for(int i=0;i<n;i++) cin >> vals[i] >> cost[i];
        // state: previous increase zero, once, or twice
        // observe that at most 2 increment per elements is needed
        array<ll, 3> dp = {0, cost[0], cost[0]*2};
        for(int i=1;i<n;i++) {
            array<ll, 3> dp2;
            dp2.fill(1e18);
            for(int j=0;j<3;j++) {
                ll val = vals[i-1] + j;
                for(int k=0;k<3;k++) {
                    ll val2 = vals[i] + k;
                    if(val == val2) continue;
                    dp2[k] = min(dp2[k], dp[j]+cost[i]*k);
                }
            }
            dp = dp2;
        }
        ll res = *min_element(dp.begin(), dp.end());
        cout << res << "\n";
    }
}
