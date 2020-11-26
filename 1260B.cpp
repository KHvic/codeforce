#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// a - 2x - y = 0
// b - 2y - x = 0
// substitute then
// 3x = 2a-b
// 3y = 2b-a
// since x & y >= 0, we perform the check

// secondly a+b = 3(x+y), need to be divisible by 3


int main(){
    fastio
    int t;
    ll a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        bool ok = ((a+b) % 3) == 0;
        ok &= (2*a-b >= 0) && (2*b-a >= 0);
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
