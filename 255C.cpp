#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, v;
    cin >> n;
    unordered_map<int,int> mapIdx;
    vector<int> vals;
    int idx = 0;
    // map distinct values to their index
    for(int i=0;i<n;i++) {
        cin >> v;
        if(!mapIdx.count(v)) mapIdx[v] = idx++;
        vals.push_back(mapIdx[v]);
    }
    // dp[i][j] => longest subsequence ending at idx i with value j as previous value
    vector<vector<int>> dp(n,vector<int>(idx,1));
    int res = 1;
    for(int i=0;i<n;i++) {
        v = vals[i];
        for(int j=0;j<i;j++) {
            dp[i][vals[j]] = max(dp[i][vals[j]], dp[j][v]+1);
            res = max(dp[i][vals[j]], res);
        }
    }
    cout << res << "\n";
}
