#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll limit = 1e7+5;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, m, l ,r, v;
    cin >> n;
    vector<int> cnt(limit, 0);
    vector<int> f(limit, 0);
    vector<bool> prime(limit, 1);
    for(int i=0;i<n;i++) {
        cin >> v;
        cnt[v]++;
    }
    for(ll i=2;i<limit;i++) {
        if(!prime[i]) continue;
        for(ll j=i;j<limit;j+=i) {
            f[i] += cnt[j];
            prime[j] = false;
        }
    }
    for(int i=1;i<limit;i++) f[i] += f[i-1];
    cin >> m;
    while(m--) {
        cin >> l >> r;
        l = min(l, limit-1);
        r = min(r, limit-1);
        cout << f[r] - f[l-1] << "\n";
    }
}
