#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int N = 100001, mod = 1e9+7;

ll cnt[N], gcdSubset[N]; // count of number i, count subset with gcd i

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res = res*x%mod;
        e >>= 1;
        x = x*x%mod;
    }
    return res;
}

int main(){
    fastio
    int n, v;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
    }
    for(int i=1;i<N;i++) {
        ll divisibleI = 0;
        for(int j=i;j<N;j+=i) {
            divisibleI += cnt[j];
        }
        // first compute all possible subset with gcd x divisible by i, where x is multiple of i
        gcdSubset[i] = powe(2, divisibleI) - 1;
    }
    for(int i=N-1;i>=1;i--) {
        for(int j=i*2;j<N;j+=i) {
            // for the i subset, we exclude all subset count that is multiple of i
            // now all subset count here only contain gcd = i
            gcdSubset[i] -= gcdSubset[j];
            gcdSubset[i] = (gcdSubset[i]+mod)%mod;
        }
    }
    cout << gcdSubset[1];
}
