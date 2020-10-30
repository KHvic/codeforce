#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, v;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        vals.push_back(0);
        vector<vector<int>> dp(2, vector<int>(n+2, 1e8));
        dp[0][0] = 0;
        for(int i=0;i<n;i++) {
            for(int j=1,hard=vals[i];j<=2;hard+=vals[i+j],j++) {
                dp[0][i+j] = min(dp[0][i+j], dp[1][i]);
                dp[1][i+j] = min(dp[1][i+j], dp[0][i] + hard);
            }
        }
        int res = min(dp[0][n] , dp[1][n]);
        cout << res << "\n";
    }
}
