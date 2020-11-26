#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    ll a, b;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> s;
        vector<vector<ll>> dp(n+1, vector<ll>(2, 1e15));
        dp[0][0] = b;
        for(int i=0;i<n;i++) {
            if(s[i]=='1' || (i && s[i-1] == '1')) dp[i][0] = 1e15;
            // 0 to 0, 1 to 0
            dp[i+1][0] = min(dp[i][0] + a + b, dp[i][1] + 2*a + 2*b);
            // 1 to 1, 0 to 1
            dp[i+1][1] = min(dp[i][1] + a + 2*b, dp[i][0] + 2*a + b);
        }
        cout << dp[n][0] << "\n";
    }
}
