#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int n, m;
const int MAXN = 1010;
int dp[4][MAXN][MAXN];
int vals[MAXN][MAXN];

int main()
{
    fastio
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> vals[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[0][i][j] = vals[i-1][j-1] + max(dp[0][i - 1][j], dp[0][i][j - 1]);
    for (int j = m; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            dp[1][i][j] = vals[i-1][j-1] + max(dp[1][i - 1][j], dp[1][i][j + 1]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp[2][i][j] = vals[i-1][j-1] + max(dp[2][i + 1][j], dp[2][i][j - 1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp[3][i][j] = vals[i-1][j-1] + max(dp[3][i][j + 1], dp[3][i + 1][j]);
    ll res = 0;
    for(int i=2;i<n;i++) {
        for(int j=2;j<m;j++) {
            ll sub = dp[0][i][j-1] + dp[1][i-1][j] + dp[2][i+1][j] + dp[3][i][j+1];
            res = max(res, sub);
            ll sub2 = dp[0][i-1][j] + dp[1][i][j+1] + dp[2][i][j-1] + dp[3][i+1][j];
            res = max(res, sub2);
        }
    }
    cout << res;
}
