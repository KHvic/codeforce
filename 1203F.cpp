#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> projs(n);
    for(int i=0;i<n;i++) cin >> projs[i].first >> projs[i].second;
    sort(projs.begin(), projs.end(), [](auto& a, auto& b) {
        // sort by positive first
        bool apos = a.second >= 0, bpos = b.second >= 0;
        if(apos && bpos) return a < b;
        else if(apos) return true;
        else if(bpos) return false;
        // both negative then do exchange argument
        int needAB = -a.second+b.first;
        int needBA = -b.second+a.first;
        return needAB < needBA;
    });
    int mx = r+n*300;
    vector<vector<int>> dp(n+1, vector<int>(mx+1, -1e8));
    dp[0][r] = 0;
    for(int i=0;i<n;i++) {
        int a = projs[i].first, b = projs[i].second;
        for(int j=0;j<=mx;j++) {
            // don't take
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            // take
            int nextj = j+b;
            if(j<a || nextj<0 || nextj > mx) continue;
            dp[i+1][nextj] = max(dp[i+1][nextj], dp[i][j] + 1);
        }
    }
    int res = *max_element(dp[n].begin(), dp[n].end());
    cout << res;
}
