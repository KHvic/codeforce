#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int mod = 1e9+7;
const int MAXN = 30000, OFFSET = 15000;
int dp[1005][MAXN]; // dp number of ways to reach sum number j ending at the ith item
int main()
{
    int n, v;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> v;
        dp[i][OFFSET + v] = dp[i][OFFSET - v] = 1;
        for(int j=0;j<MAXN;j++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j-v]) % mod;
            dp[i][j] = (dp[i][j] + dp[i-1][j+v]) % mod;
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++) res = (res + dp[i][OFFSET]) % mod;
    cout << res;
}
