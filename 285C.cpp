#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n, v;
    vector<ll> vs;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> v;
        vs.push_back(v);
    }
    sort(vs.begin(), vs.end());
    ll res = 0;
    for(ll i=1;i<=n;i++) {
        res += abs(i-vs[i-1]);
    }
    cout << res << "\n";
}
