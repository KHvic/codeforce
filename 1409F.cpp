#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
 
const ll INF = -1e9;
 
ll n,k;
string a, b;
 
ll dp[205][205][205];
 
ll solve(int idx, int first, int left) {
    if(left<0) return INF;
    if(idx>=n) {
        return 0;
    } else if(dp[idx][first][left] != -1) return dp[idx][first][left];
 
    bool isfirst = b[0] == a[idx];
    bool issecond = b[1] == a[idx];
    ll res = solve(idx+1, first + isfirst, left) + issecond*first;
    // go first
    if(!isfirst) {
        ll res2 = solve(idx+1, first+1, left-1);
        res = max(res2, res);
    }
    if(!issecond) {
        ll res3 = solve(idx+1, first, left-1) + first;
        res = max(res3, res);
    }
    return dp[idx][first][left] = res;
}
 
ll solve1() {
    char c = b[0];
    ll cnt = count(a.begin(), a.end(), c);
    ll take = min(k, n-cnt);
    ll mx = cnt+take;
    mx--;
    return mx*(mx+1)/2;
}
 
int main(){
    fastio
 
    cin >> n >> k;
    cin >> a >> b;
    if(b[0] == b[1]) cout << solve1() << "\n";
    else {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int x=0;x<k+1;x++) dp[i][j][x] = -1;
        cout << solve(0, 0, k) << "\n";
    }
}
