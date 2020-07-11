#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1,-1e8);
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        if(i-a>=0) dp[i] = max(dp[i], dp[i-a]+1);
        if(i-b>=0) dp[i] = max(dp[i], dp[i-b]+1);
        if(i-c>=0) dp[i] = max(dp[i], dp[i-c]+1);
    }
    cout << max(dp[n], 0);
}
