#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, m, s;
vector<vector<int>> precompute;

void compute(vector<int>& shelf) {
    int m = shelf.size();
    vector<int> res(m+1);
    for(int i=1;i<=m;i++) {
        int sum = 0;
        for(int j=0;j<i;j++) sum += shelf[j];
        int best = sum;
        for(int j=0;j<i;j++) {
            sum -= shelf[i-1-j];
            sum += shelf[m-1-j];
            best = max(sum, best);
        }
        res[i] = best;
    }
    precompute.push_back(res);
}

vector<vector<int>> dp;

int solve(int idx, int left) {
    if(left<0) return -1e9;
    else if(idx>=n) return 0;
    else if(dp[idx][left] != -1) return dp[idx][left];
    int res = solve(idx+1, left);
    for(int i=1;i<precompute[idx].size();i++) {
        res = max(res, solve(idx+1, left-i) + precompute[idx][i]);
    }
    return dp[idx][left] = res;
}

int main(){
    fastio
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s;
        vector<int> sh(s);
        for(int j=0;j<s;j++) cin >> sh[j];
        compute(sh);
    }
    dp.assign(n, vector<int>(m+1, -1));
    cout << solve(0, m);
}
