#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// every number other 1 is divisible by some prime p
// p*a = x

int main(){
    fastio
    int t;
    ll x, y;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        x -= y;
        cout << (x==1 ? "NO\n" : "YES\n");
    }
}
