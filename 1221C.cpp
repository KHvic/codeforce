#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int q;
    ll c, m, x;
    cin >> q;
    while(q--) {
        cin >> c >> m >> x;
        ll res = min(c, min(m, x));
        c -= res; m -= res; x -= res;
        // assume x is 0 now
        ll mx = min(c, m);
        res += min(mx, (c+m)/3);
        cout << res << "\n";
    }
}
