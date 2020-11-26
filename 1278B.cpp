#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// observation 1:
// sa + sb = n*(n+1)/2
// sa - sb = a - b // assume a is larger
// sa = (n*(n+1)/2 + a - b)/2
// shows that sa = n*(n+1)/2 and (a-b) must have same parity

// observation 2:
// can form any subset [1 to n*(n+1)/2]

// in total find the smallest n such that we fulfill observation 2 and has same parity as a-b

int main(){
    fastio
    int t;
    ll a, b;
    cin >> t;

    auto f = [](ll x) {
        return x*(x+1)/2;
    };
    while(t--) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        int diff = b-a;
        ll val = sqrt(diff*2);

        while(f(val) < diff || f(val) % 2 != diff % 2) {
            val++;
        }
        cout << val << "\n";
    }
}
