#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 998244353;

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
    int n;
    cin >> n;
    map<int, int> lastpos;
    vector<int> vals(n);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        lastpos[vals[i]] = i;
    }
    int last = 0, groups = 0;
    for(int i=0;i<n;i++) {
        last = max(lastpos[vals[i]], last);
        if(i==last) {
            groups++;
            last++;
        }
    }
    ll res = powe(2, groups-1);
    cout << res;
}
