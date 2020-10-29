#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 351;
int dp[N][N];
vector<int> items;

int solve(int idx, int t) {
    if(idx>=items.size()) return 0;
    else if(t>=N) return 1e8;
    else if(dp[idx][t] != -1) return dp[idx][t];
    int res = 1e8;
    for(int i=t;i<N;i++) {
        res = min(res, solve(idx+1, i+1) + abs(i-items[idx]));
    }
    return dp[idx][t] = res;
}

int main(){
    fastio
    int t,n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        items.assign(n, 0);
        for(int i=0;i<n;i++) cin >> items[i];
        sort(items.begin(), items.end());
        memset(dp, -1, sizeof dp);
        cout << solve(0, 1) << "\n";
    }
}
