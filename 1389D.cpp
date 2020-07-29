#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int mod = 1e9+7;
int t;
ll n,k;
ll l, r, x, y;
vector<ll> intersect() {
    ll mxl = max(l, x);
    ll mnr = min(r,y);
    ll mnl = min(l, x);
    ll mxr = max(r, y);
    if(mxl > mnr) return {0, mxl - mnr, mxr-mnl};
    ll inter = mnr - mxl;
    return {inter, 0, mxr-mnl - inter};
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> l >> r >> x >> y;
        auto pre = intersect();
        ll connectcost = pre[1];
        ll inter = pre[0];
        k -= n*inter;
        if(k<=0) {
            cout << 0 << "\n";
            continue;
        }
        ll res = 0;
        for(int i=0;i<n && k>0;i++) {
            ll totalcost = connectcost;
            ll take = min(k, pre[2]);
            totalcost += take;
            ll costsave = take*2 - totalcost;
            if(i>0 && costsave<=0) break;
            k -= take;
            res += totalcost;
        }
        if(k>0) res += k*2;
        cout << res << "\n";
    }
}
