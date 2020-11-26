#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    ll x;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        vector<pair<ll, ll>> blows(n);
        ll mxd = 0, mxchange = 0;
        for(int i=0;i<n;i++) {
            cin >> blows[i].first >> blows[i].second;
            mxd = max(mxd, blows[i].first);
            mxchange = max(mxchange, blows[i].first - blows[i].second);
        }
        if(mxd<x && mxchange==0) {
            cout << "-1\n"; continue;
        }
        ll res = 1;
        x = max(0LL, x-mxd);
        if(x) res += (x+mxchange-1)/mxchange;
        cout << res << "\n";
    }
}
