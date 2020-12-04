#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 501, INF = 1e9;

int main(){
    fastio
    int t, n, x;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        vector<int> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];

        // dp state: idx, prev_max, x
        vector<vector<int>> dp(N, vector<int>(N, INF));
        dp[0][x] = 0;
        for(int i=0;i<n;i++) {
            int v = vals[i];
            vector<vector<int>> ndp(N, vector<int>(N, INF));
            for(int j=0;j<N;j++) {
                for(int k=0;k<N;k++) {
                    if(dp[j][k] == INF) continue;
                    // choice1: leave vals[i] as this position
                    if(v >= j) ndp[v][k] = min(ndp[v][k], dp[j][k]);
                    // choice2 : leave x here
                    if(v > k && k >= j) ndp[k][v] = min(ndp[k][v], dp[j][k] + 1);
                }
            }
            dp = ndp;
        }
        int res = INF;
        for(int i=0;i<N;i++) res = min(res, *min_element(dp[i].begin(), dp[i].end()));
        cout << (res < INF ? res : -1) << "\n";
    }
}
