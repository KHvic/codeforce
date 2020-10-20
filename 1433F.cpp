#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const int N = 72;
 
int n, c, k;
int dp1[N][N][N][N];
int tx[N][N];
vector<vector<int>> vals;
int solve1(int r, int idx, int l, int m) {
    if(l<0) return -1e8;
    else if(l==0||idx>=c) return m==0 ? 0 : -1e8;
    else if(dp1[r][idx][l][m] != -1) return dp1[r][idx][l][m];
    return dp1[r][idx][l][m] = max(solve1(r, idx+1, l, m), solve1(r, idx+1, l-1, (m+vals[r][idx])%k) + vals[r][idx]);
}
 
int main(){
    fastio
    cin >> n >> c >> k;
    memset(dp1, -1, sizeof dp1);
    vals = vector<vector<int>>(n, vector<int>(c));
    for(int i=0;i<n;i++)
        for(int j=0;j<c;j++) cin >> vals[i][j];
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            tx[i][j] = solve1(i, 0, c/2, j);
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1e8));
    dp[0][0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            for(int x=0;x<k;x++) {
                int nj = (j+x)%k;
                dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + tx[i][x]);
            }
        }
    }
    cout << dp[n][0];
}
