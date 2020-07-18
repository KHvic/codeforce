#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MX = sqrt(1e12) + 10;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, v;
    bool isprime[MX];
    memset(isprime, 1, sizeof isprime);

    for(ll i=2;i<MX;i++) {
        if(isprime[i]) for(ll j=i*i;j<MX;j+=i) isprime[j] = false;
    }
    cin >> n;
    // a^2 = 3, a number with exactly one divisor but is a square number
    for(int i=0;i<n;i++) {
        cin >> v;
        ll sq = sqrt(v);
        if(v!= 1 && sq*sq == v && isprime[sq]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
