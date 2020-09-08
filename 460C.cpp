#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n,m,w;
    cin >> n >> m >> w;
    vector<ll> vals(n);
    ll mx = 0;
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        mx = max(mx, vals[i]);
    }

    auto can = [&](ll t) {
        ll left = m;
        vector<int> offset(n+w+1);
        ll cur = 0;
        for(int i=0;i<n;i++) {
            cur += offset[i];
            ll need = max(t - (vals[i]+cur), 0LL);
            left -= need;
            if(left<0) return false;
            cur += need;
            offset[i+w] -= need;
        }
        return true;
    };

    ll low = 1, hi = mx+m;
    while(low<hi) {
        ll mid = (low+hi+1) >> 1;
        if(can(mid)) low = mid;
        else hi = mid-1;
    }
    cout << low;
}
