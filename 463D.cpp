#include<bits/stdc++.h>
using namespace std;
#define ll long long

// since number are distinct
// an item a[i] > a[j] iff for all k subsequence a[i] comes after a[j]

// two possible solution
// 1. dp longest subsequence fulfilling the above condition
// 2. build graph where a[i] -> a[j] if condition above is met, find longest path for this graph

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int vals[k][n];
    int pos[k][n+1];
    for(int i=0;i<k;i++) {
        for(int j=0;j<n;j++) {
            cin >> vals[i][j];
            pos[i][vals[i][j]] = j;
        }
    }
    int dp[n];
    memset(dp, 0, sizeof dp);
    int res = 0;
    for(int i=0;i<n;i++) {
        int v1 = vals[0][i];
        for(int j=0;j<i;j++) {
            int v2 = vals[0][j];
            // ok if for all k sequence, v2 before v1
            bool ok = true;
            for(int x=0;x<k&&ok;x++)
                if(pos[x][v1] < pos[x][v2]) ok = false;
            if(ok) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
        res = max(dp[i], res);
    }
    cout << res;
}
