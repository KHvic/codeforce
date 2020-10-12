#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// observation:
// 1. 0 must be the last product seq (n must be last), if 0 is not => xxxx0000, all future seq is 0 (multi 0)
// hence first n-1 number = (n-1)! % n != 0
// notice, prime numbers always fulfill this condition

// 2. composite number x > 4, (x-1)! % n == 0, violating condition
// proof: x = p*q
// case 1: p != q, then (x-1)! % (p*q) == 0, because p and q are two smaller number than x
// case 2: p == q, then (x-1)! % (p^2) == 0, for any x = p^2 > 4, p < x

// 3.
// n = 1: 1
// n = 4: 1, 3, 2, 4
// n is prime: a[i] = i/(i-1)%n (inverse)
// proof by contradiction, i/(i-1) == j/(j-1) then i==j which isn't possible

bool isPrime(int x) {
    for(ll i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
}

int main(){
    fastio
    int n;
    cin >> n;
    if (n==1) {
        cout << "YES\n1";
    } else if(n==4) {
        cout << "YES\n1\n3\n2\n4";
    } else if(isPrime(n)) {
        vector<ll> inv(n, 1);
        cout << "YES\n1\n";
        for(int i=2;i<n;i++) {
            // https://cp-algorithms.com/algebra/module-inverse.html
            inv[i] = (ll)(n-n/i) * inv[n % i] % n;
            cout << (inv[i-1] * i % n) << "\n";
        }
        cout << n;
    } else {
        cout << "NO\n";
    }
}
