#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll dp[105][2];
ll mod = 1e9+7;
int n, k, d;

ll solve(int val, bool has_d) {
    if(val<0) return 0;
    else if(val==0) return has_d;
    else if(dp[val][has_d] != -1) return dp[val][has_d];

    ll res = 0;
    for(int i=1;i<=k;i++) res = (res + solve(val-i, has_d | (i>=d))) % mod;
    return dp[val][has_d] = res;
}

int main(){
    fastio
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    cout << solve(n, 0);
}
