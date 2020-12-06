#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll countMSD1(ll x) {
    if(x==0) return 0;
    ll curd = 1, res = 0;
    while(curd < 1e18 && curd*10 <= x) {
        res += curd;
        curd *= 10;
    }
    return res + min(x-curd+1, curd);
}

int main(){
    fastio
    int n, k;
    cin >> n;
    ll l, r;
    vector<double> prob(n);
    for(int i=0;i<n;i++) {
        cin >> l >> r;
        double valid = countMSD1(r) - countMSD1(l-1);
        double total = r-l+1;
        prob[i] = valid/total;
    }
    cin >> k;
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            dp[i+1][j] += dp[i][j]*(1-prob[i]);
            dp[i+1][j+1] += dp[i][j]*prob[i];
        }
    }
    // x >= k*n/100
    // x*100 >= k*n
    double res = 0;
    for(int x=0;x<=n;x++)
        if(x*100 >= k*n)
            res += dp[n][x];
    cout << fixed << setprecision(10) << res;
}
