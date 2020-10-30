#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll x, y, k;
    cin >> t;
    while(t--) {
        cin >> x >> y >> k;
        ll total = k + k*y - 1;
        ll per_trade = x-1;
        cout << (total+per_trade-1)/per_trade + k << "\n";
    }
}
