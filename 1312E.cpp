#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];

    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0;i<n;i++) dp[i][i] = vals[i];
    for(int len=2;len<=n;len++) {
        for(int alen=1;alen<len;alen++) {
            for(int i=0;i+len<=n;i++) {
                int v1 = dp[i][i+alen-1], v2 = dp[i+alen][i+len-1];
                if(v1==0 || v2==0 || v1!=v2) continue;
                dp[i][i+len-1] = v1+1;
            }
        }
    }
    vector<int> dp2(n+1, 1e8);
    dp2[0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(dp[i][j] != 0) dp2[j+1] = min(dp2[j+1], dp2[i]+1);
        }
    }
    cout << dp2.back();
}
