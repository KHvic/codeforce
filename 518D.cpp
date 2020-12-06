#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, t;
    double p;
    cin >> n >> p >> t;
    double dp[t+1][n+1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i=0;i<t;i++) {
        for(int j=0;j<=n;j++) {
            if(j==n) dp[i+1][j] += dp[i][j];
            else {
                dp[i+1][j] += dp[i][j]*(1-p);
                dp[i+1][j+1] += dp[i][j]*p;
            }
        }
    }

    double res = 0;
    for(int i=0;i<=n;i++) res += dp[t][i]*i;
    cout << fixed << setprecision(10) << res;
}
