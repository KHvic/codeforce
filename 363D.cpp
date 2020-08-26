#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n,m,a;
    cin >> n >> m >> a;
    vector<ll> boys(n), bikes(m);
    for(int i=0;i<n;i++) cin >> boys[i];
    sort(boys.begin(), boys.end());
    for(int i=0;i<m;i++) cin >> bikes[i];
    sort(bikes.begin(), bikes.end());

    auto can = [&](int k) {
        ll leftover = a;
        ll spent = 0; // personal spending
        for(int i=0;i<k;i++) {
            ll need = bikes[i] - boys[n-k+i];
            leftover -= max(need, 0LL);
            spent += min(bikes[i], boys[n-k+i]);
        }
        bool valid = leftover >= 0;
        ll minPersonalSpent = max(spent - leftover, 0LL);
        return make_pair(valid, minPersonalSpent);
    };

    int low = 0, high = min(n,m);
    ll mnSpent = 0;
    while(low<high) {
        int mid = (low+high+1) >> 1;
        auto subres = can(mid);
        if(subres.first) {
            low = mid;
            mnSpent = subres.second;
        } else high = mid-1;
    }
    cout << low << " " << mnSpent;
}
