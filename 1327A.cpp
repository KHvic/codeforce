#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool ok = k%2 == n%2 && (n >= k*k);
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
