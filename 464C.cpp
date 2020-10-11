#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int mod = 1e9+7;

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
    string s, a;
    cin >> s;
    int q;
    cin >> q;

    vector<ll> transform_val(10), transform_len(10);
    for(int i=0;i<10;i++) transform_val[i] = i, transform_len[i] = 1;
    vector<string> queries;
    queries.push_back("0->" + s);
    while(q--) {
        cin >> a;
        queries.push_back(a);
    }
    for(auto it=queries.rbegin();it!=queries.rend();it++) {
        a = *it;
        int v = a[0]-'0';
        ll to_len = 0, to_val = 0;
        for(int i=a.size()-1;i>=3;i--) {
            int idx = a[i] - '0';
            to_val = (to_val + transform_val[idx] * powe(10, to_len) % mod) % mod;
            to_len += transform_len[idx];
        }
        transform_val[v] = to_val;
        transform_len[v] = to_len % (mod - 1); // fermat little theorem, 10^(p-1) => 1 mod p
    }
    cout << transform_val[0];
}
