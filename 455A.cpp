#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5+10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, v;
    cin >> n;
    ll res = 0;
    ll dp[MAXN];
    memset(dp, 0, sizeof dp);
    unordered_map<ll, int> cnt;
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
    }
    for(ll i=1;i<MAXN;i++) {
        dp[i] = max(dp[i-1], (i-2>=0 ? dp[i-2] : 0) + (i*cnt[i]));
        res = max(dp[i], res);
    }
    cout << res;
}
