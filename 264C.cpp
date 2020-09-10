#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n,m;
    cin >> n >> m;
    vector<int> vals(n), cols(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    for(int i=0;i<n;i++) cin >> cols[i];
    function<ll(int a, int b)> compute = [&](ll a, ll b) -> ll {
        vector<ll> dp(n+1, -1e15);
        dp[0] = 0;
        int mx1 = 0, mx2 = 0;
        for(int i=0;i<n;i++) {
            int c = cols[i], v = vals[i];
            ll same = dp[c] + a*v;
            ll diff = (mx1 == c ? dp[mx2] : dp[mx1]) + b*v;
            ll best = max(dp[c],max(same, diff));
            if(c != mx1 && best > dp[mx1]) {
                mx2 = mx1;
                mx1 = c;
            } else if(c != mx1 && best > dp[mx2]) {
                mx2 = c;
            }
            dp[c] = best;
        }
        return dp[mx1];
    };
    int a, b;
    while(m--) {
        cin >> a >> b;
        cout << compute(a, b) << "\n";
    }
}
