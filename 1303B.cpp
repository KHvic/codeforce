#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll n, g, b;
    cin >> t;
    while(t--) {
        cin >> n >> g >> b;
        ll needg = (n+1)/2;
        ll times = (needg-1)/g;
        ll res = max(times*b + needg, n);
        cout << res << "\n";
    }
}
