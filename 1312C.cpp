#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll mx = 0;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i], mx = max(mx, vals[i]);
        int e = max((ll)(log(mx)/log(k)) + 1, 1LL);
        bool ok = true;
        ll v = pow(k, e);
        for(;v>0&ok; v/=k) {
            int cnt = 0;
            for(auto& x : vals) {
                if(x>=v) {
                    x -= v;
                    cnt++;
                }
            }
            ok &= (cnt<=1);
        }
        mx = *max_element(vals.begin(), vals.end());
        ok &= mx==0;
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
