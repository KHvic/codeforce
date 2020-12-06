#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// observation: one vertex of color A can only be connected to at most one vertex of color B
// reduce the problem to ways to connect color A to color B
// we can solve for all three colors independently
// A to B, A to C, B to C
// multiply solutions to these problems to form up the final result

const int N = 5005, mod = 998244353;
ll dp[N][N];

ll solve(int a, int b) {
    memset(dp, 0, sizeof dp);
    // ways of num node processed a, b
    dp[0][0] = 1;
    for(int i=0;i<a;i++) {
        for(int j=0;j<=b;j++) {
            int left = b-j;
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod; // don't connect
            dp[i+1][j+1] = (dp[i+1][j+1] + left*dp[i][j]) % mod; // connect to one of the second node
        }
    }
    ll res = 0;
    for(int i=0;i<=b;i++) res = (res + dp[a][i]) % mod;
    return res;
}

int main(){
    fastio
    int a, b, c;
    cin >> a >> b >> c;
    ll waysAB = solve(a, b);
    ll waysAC = solve(a, c);
    ll waysBC = solve(b, c);
    ll res = waysAB*waysAC%mod*waysBC%mod;
    cout << res;
}
