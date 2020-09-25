#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, k;
    cin >> n >> k;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];

    auto can = [&](ll t) {
        vector<int> dp(n, 1e8); // min cost to make vals[0:i] valid
        for(int i=0;i<n;i++) {
            dp[i] = i;
            for(int j=0;j<i;j++) {
                if(abs(vals[i] - vals[j]) <= t*(i-j))
                    dp[i] = min(dp[i], dp[j] + (i-j-1));
            }
            int cost = n - (i+1) + dp[i];
            if(cost <= k) return true;
        }
        return false;
    };
    ll low = 0, hi = 2LL*1e9+5;
    while(low<hi) {
        ll mid = (low+hi)/2;
        if(can(mid)) hi = mid;
        else low = mid+1;
    }
    cout << low;
}
