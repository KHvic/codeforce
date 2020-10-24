#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
// observation 1: optimal segment has min/max in the borders
// observation 2: segment is either mono increasing or decreasing

int main(){
    fastio
    int n;
    cin >> n;
    vector<ll> vals(n), dp(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    for(int i=1;i<n;i++) {
        if(vals[i] > vals[i-1]) {
            if(i==1 || vals[i-1] > vals[i-2]) dp[i] = dp[i-1]+vals[i]-vals[i-1]; // merge with previous seg
            else dp[i] = max(dp[i-1], vals[i]-vals[i-1]+dp[i-2]); // two choice, i-1 start a new seg or i start a new seg
        } else {
            if(i==1 || vals[i-1] < vals[i-2]) dp[i] = dp[i-1]+vals[i-1]-vals[i]; // merge with previous seg
            else dp[i] = max(dp[i-1], vals[i-1]-vals[i]+dp[i-2]);
        }
    }
    cout << dp[n-1];
}
