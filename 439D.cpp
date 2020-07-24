#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, b;
ll f(ll k) {
    ll res = 0;
    // cost to raise all to >= k
    for(ll x : a)
        if(k > x)
            res += k - x;
    // cost to reduce all to <= k
    for(ll x : b)
        if(k < x)
            res += x - k;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ternary search on convex function
    ll n, m, v;
    cin >> n >> m;
    while(n--) {
        cin >> v;
        a.push_back(v);
    }
    while(m--) {
        cin >> v;
        b.push_back(v);
    }
    ll low = 0, high = 1e9;
    ll res = 1e18;
    for(int i=0;i<100;i++) {
        ll mn = low + (high-low)/3;
        ll mx = high - (high-low)/3;
        ll fmn = f(mn);
        ll fmx = f(mx);
        res = min(res, min(fmn, fmx));
        if(fmn < fmx) {
            high = mx;
        } else {
            low = mn;
        }
    }
    cout << res;
}
