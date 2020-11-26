#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// let gcd(a,m) = G
// then a = G*x, m = G*y
// and (a+x) = G*(x+z)
// since we know gcd(x,y) = 1
// then reduce the question to find all numbers between x to x+y that is coprime to y
// secondly, by definition of euclidean algorithm gcd(x,y) = gcd(x%y,y) if x>y
// reducing the problem to find all integer coprime to y since x%y < y

ll phi(ll x) {
    ll res = x;
    for(ll i=2;i*i<=x;i++) {
        if(x%i==0) {
            res -= res/i;
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res -= res/x;
    return res;
}

int main(){
    fastio
    int t;
    ll a, m;
    cin >> t;
    while(t--) {
        cin >> a >> m;
        cout << phi(m/__gcd(a, m)) << "\n";
    }
}
