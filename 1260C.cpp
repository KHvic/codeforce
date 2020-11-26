#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll r, b, k;
    cin >> t;
    while(t--) {
        cin >> r >> b >> k;
        if(r > b) swap(r, b); // r smaller
        ll d = __gcd(r, b);
        r /= d; b /= d;
        if((k-1)*r + 1 < b) cout << "REBEL\n";
        else cout << "OBEY\n";
    }
}
