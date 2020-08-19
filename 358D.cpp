#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 3005;
int n;
int joy[3][MAXN];
int dp[MAXN][2];

int solve(int idx, bool prevFirst) {
    int order=prevFirst;
    if(idx>=n) return 0;
    else if(dp[idx][prevFirst] != -1) return dp[idx][prevFirst];

    // idx go first
    int res = solve(idx+1, 1) + joy[order][idx];
    // idx go later
    if(idx!=n-1) {
        res = max(solve(idx+1, 0) + joy[order+1][idx], res);
    }
    return dp[idx][prevFirst] = res;
}

int main(){
    fastio
    cin >> n;
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++)
            cin >> joy[i][j];
    memset(dp, -1, sizeof dp);
    cout << solve(0,0);
}
