#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n;
    cin >> n;
    ll mod = 1e9+7;
    ll a=0,d=1;
    for(int i=0;i<n;i++) {
        // d = a+b+c = 3*a
        ll d2 = (a*3) % mod;
        // a/b/c = d+2a
        ll a2 = (d+2*a) % mod;
        a = a2; d = d2;
    }
    cout << d;
}
