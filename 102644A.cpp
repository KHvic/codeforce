#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n;
    double e; // probably of switching mood in x seconds, 1, 2, 4, 8, 16...
    cin >> n  >> e;
    // binary exponentiation
    double res = 1;
    while(n) {
        if(n&1) res = res*(1-e) + (1-res)*e;
        n >>= 1;
        e = 2.0*(1.0-e)*e;
    }
    cout << fixed << setprecision(12) << res;
}
