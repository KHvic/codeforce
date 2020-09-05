#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
 
int main(){
    fastio
    ll t, a, b, x, y, n;
    cin >> t;
    while(t--) {
        cin >> a >> b >> x >> y >> n;
        ll mna = max(a-n,x), mnb = max(b-n, y);
        if(mna<mnb) {
            ll take = a-mna;
            ll left = n-take;
            mnb = max(b-left, y);
        } else {
            ll take = b-mnb;
            ll left = n-take;
            mna = max(a-left, x);
        }
        cout << mna*mnb << "\n";
    }
}
