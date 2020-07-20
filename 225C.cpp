#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    vector<int> cntdot(m+1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cntdot[j+1] += grid[i][j] == '.';
    for(int i=1;i<=m;i++) cntdot[i] += cntdot[i-1];

    int dp[m+1][2]; // dp state: column, color ending at color
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = dp[0][1] = 0;

    for(int i=0;i<m;i++) {
        for(int j=x;j<=y;j++) {
            int ni = i+j;
            if(ni>m) break;
            int costa = cntdot[ni] - cntdot[i];
            int costb = (ni-i)*n - costa;
            dp[ni][0] = min(dp[ni][0], dp[i][1] + costa);
            dp[ni][1] = min(dp[ni][1], dp[i][0] + costb);
        }
    }
    cout << min(dp[m][0], dp[m][1]) << "\n";
}
