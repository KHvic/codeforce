#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll a, b, x, y;
    cin >> t;
    while(t--) {
        cin >> x >> y >> a >> b;
        if(y<x) swap(x, y);
        ll costA = (x+y)*a, costB = x*b + (y-x)*a;
        cout << min(costA, costB) << "\n";
    }
}
