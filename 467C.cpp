#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 5005;
ll n,m,k,p;
vector<ll> prefix;
ll dp[MAXN][MAXN];

ll val(int idx) {
    return prefix[idx+m] - prefix[idx];
}

ll solve(int idx, int k) {
    if(k==0) return 0;
    else if(idx+m>=prefix.size()) return -1e8;
    else if(dp[idx][k] != -1) return dp[idx][k];
    ll res = max(solve(idx+1, k),
                 val(idx) + solve(idx+m, k-1));
    return dp[idx][k] = res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    prefix.push_back(0);
    for(int i=0;i<n;i++) {
        cin >> p;
        p += prefix.back();
        prefix.push_back(p);
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, k);
}
