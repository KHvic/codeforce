#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll x, y;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        bool ok = true;
        unordered_set<ll> seen;
        seen.insert(y);
        while(y>x && ok) {
            if(y%3==0) y = y/3*2;
            else {
                y += 3-(y%3);
                if(seen.count(y)) ok = false;
                else seen.insert(y);
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
